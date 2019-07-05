/**
 * 既然字母可以重排,则每个字母出现的位置并不重要,重要的是每个字母出现的次数
 */

#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int cnt1[26];
int cnt2[26];

char buf[101];
char buf1[101];

int main(){
    while(scanf("%s",buf)){
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        char ch = getchar();//去除回车
        scanf("%s",buf1);
        int len_buf = strlen(buf);
        int len_buf1 = strlen(buf1);
        if(len_buf1 != len_buf){
            puts("NO!");
        }
        for(int i = 0;i < len_buf;i ++){
            cnt1[buf[i] - 'A'] ++;
            cnt2[buf1[i] - 'A'] ++;
        }
        bool flg = true;
        for(int i = 0;i < 26;i ++){
            if(cnt1[i] != cnt2[(i + 25) % 26]){
                puts("NO!");
                flg = false;
                break;
            }
        }
        if(flg){
            puts("YES!");
        }

    }
    return 0;
}

