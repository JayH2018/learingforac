#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 105


using namespace std;

char b[maxn];
char a[5][5];

int main(){

    int tmpi,tmpj;
    for(int i = 0;i < 5;i ++){
        for(int j = 0;j < 5;j ++){
            a[i][j] = getchar();
            if(a[i][j] == ' '){
                tmpi = i;
                tmpj = j;
            }
        }
        char ch = getchar();//吃掉回车
    }
//    for(int i = 0;i < 5;i ++){
//        puts(a[i]);
//    }
    while(scanf("%s",b)){
        int len_b = strlen(b);
        bool isTrue = false;
        for(int i = 0;i < len_b;i ++){
            switch(b[i]){
            case 'A':
                if(tmpi < 1){
                    printf("This puzzle has no final configuration!");
                    isTrue = true;
                }
                swap(a[tmpi][tmpj],a[tmpi - 1][tmpj]);
                tmpi --;
                break;
            case 'B':
                if(tmpi > 4){
                    printf("This puzzle has no final configuration!");
                    isTrue = true;
                }
                swap(a[tmpi][tmpj],a[tmpi + 1][tmpj]); //实在搞不明白当tmpi = 0时,a[++tmpi][tmpj]修改的依旧是a[0][tmpj]的值。
                tmpi ++;
                break;
            case 'L':
                if(tmpj < 1){
                    printf("This puzzle has no final configuration!");
                    isTrue = true;
                }
                swap(a[tmpi][tmpj],a[tmpi][tmpj - 1]);
                tmpj --;
                break;
            case 'R':
                if(tmpj > 4){
                    printf("This puzzle has no final configuration!");
                    isTrue = true;
                }
                swap(a[tmpi][tmpj],a[tmpi][tmpj + 1]);
                tmpj++;
                break;
            case '0':
                break;
            default:
                printf("This puzzle has no final configuration!");
                isTrue = true;
            }
            if(isTrue){
                break;
            }
        }
        if(isTrue){
            continue;
        }else{
            for(int i = 0;i < 5;i ++){
                for(int j = 0;j < 5;j ++){
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }
        }

    }
    return 0;
}
