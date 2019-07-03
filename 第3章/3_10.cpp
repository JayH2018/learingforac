/**
 * 本题只需要判断是否存在两个或以上的偶数个对应相等的矩形即可。
 * 本题因为1<=wi,hi<=1000;所以可以用二维数组模拟哈希。
 * 如果本题wi,hi较大。可以借用结构体和排序（先排wi再排hi）来实现
 */

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

char a[1001][1001];

int main(){

    char c1,c2;
    bool flag = false;
    while(scanf("%d%d",&c1,&c2)){
        for(int i = 0;i < 1001;i ++){
            memset(a[i],0,sizeof(a[i]));
        }
        a[c1][c2] ++;
        for(int i = 1;i < 6;i ++){
            scanf("%d%d",&c1,&c2);
            a[c1][c2] ++;
        }
        for(int i = 0;i < 1001;i ++){
            for(int j = 0;j < 1001;j ++){
                if(a[i][j] % 2 != 0){
                    flag = true;
                }
            }
        }
        if(!flag){
            puts("Possible!");
        }else{
            puts("Impossible!");
        }
    }
    return 0;
}
