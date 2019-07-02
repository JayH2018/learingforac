#include<stdio.h>
#include<string.h>
/**
 * 假设a是商  b是余数
 * a=1/7=0, b=1%7=1;
 * a=(b*10)/7=1, b=(b*10)%7=3;
 * a=(b*10)/7=4, b=(b*10)%7=2;
 * a=(b*10)/7=2  ,  b=(b*10)%7=6;
 * a=(b*10)/7=8  ,  b=(b*10)%7=4;
 * a=(b*10)/7=5  ,  b=(b*10)%7=5;
 * a=(b*10)/7=7  ,  b=(b*10)%7=1;   //与已有的余数相同开始循环
 * a=(b*10)/7=1  ,  b=(b*10)%7=3;
 */



int d;

int main(){
    int a,b;
    int e,f;
    int c[101];
    while(scanf("%d%d",&a,&b)){
        e = a / b;
        int i = 0;
        c[i++] = e;
        f = a % b;
        while(i < 3 || !(c[1] == c[i - 2] && c[2] == c[i - 1] && i != 3)){
            c[i++] = (f * 10) / b;
            f = (f * 10) % b;
        }
        printf("%d.",c[0]);
        for(int j = 1;j < i - 2;j ++){
            printf("%d",c[j]);
        }
        printf("\n");
    }
    return 0;
}
