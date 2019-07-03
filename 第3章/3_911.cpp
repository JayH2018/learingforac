/**
 * 本题有两种思路：
 * 一：将A长条固定，再将B长条先向左边移动，然后再向右边移动。求两次移动过程中最小值。
 * 二：将A长条固定，再将B长条向右边移动。再将B长条固定,然后再将A长条向右边移动。求两次移动过程中最小值。
 */

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int a[101];
int b[101];

char c[101];
char d[101];

int qiuminlen(int a[],int b[],int len_a,int len_b){

    int minlen = 0x7fffffff;
    bool flag = false;
    int i = 0,j = 0;
    for(;i < len_a;i ++){
        flag = false;
        for(j = 0;j < len_b;j ++){
            if(a[i + j] + b[j] >= 4){
                flag = true;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    return len_b < (len_a - i) ? len_a : (len_a + len_b) - (len_a - i);
}

int main(){
    while(scanf("%s",c)){
        int len_c = strlen(c);
        for(int i = 0;i < len_c;i ++){
            a[i] = c[i] - '0';
        }
        scanf("%s",d);
        int len_d = strlen(d);
        for(int i = 0;i < len_d;i ++){
            b[i] = d[i] - '0';
        }
        int minlen = min(qiuminlen(a,b,len_c,len_d),qiuminlen(b,a,len_d,len_c));
        printf("%d\n",minlen);
    }
    return 0;
}
