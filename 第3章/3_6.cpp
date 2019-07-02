#include<stdio.h>



int main(){
    int r,c;
    char a[10][10];
    while(scanf("%d%d",&r,&c)){
        char ch = getchar();//吃掉回车
        for(int i = 0;i < r;i ++){
            for(int j = 0;j < c;j ++){
                scanf("%c",&a[i][j]);
            }
            ch = getchar();//吃掉回车
        }
        //输出Acorss
        puts("Acorss");
        for(int i = 0;i < r;i ++){
            for(int j = 0;j < c;j ++){
                if(a[i][j] == '*') continue;
                if(j == 0 || a[i][j - 1] == '*'){
                    for(int k = j;a[i][k] != '*' && k < c;k ++){
                        printf("%c",a[i][k]);
                    }
                    printf("\n");
                }

            }
        }

        //输出Down
        puts("Down");
        for(int i = 0;i < r;i ++){
            for(int j = 0;j < c;j ++){
                if(a[i][j] == '*') continue;
                if(i == 0 || a[i - 1][j] == '*'){
                    for(int k = i;a[k][j] != '*' && k < r;k ++){
                        printf("%c",a[k][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
