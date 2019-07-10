/**
  * 本题尚未完成，日后完善
  */

#include<stdio.h>
#include<iostream>
unsigned long long a[7][101];
using namespace std;
#define BIG 1000

int cols[101];
char a1[1][101][65];

int tmpcols[101];

//char b[1000001][4];

void printCols(){
    for(int i = 0;i < 101;i ++){
        printf("%d ",cols[i]);
    }
}

bool isinCols(int i,int j){
    int tmp = i * BIG + j;
    for(int k = 0;k < 101;k ++){
        if(cols[k] == tmp){
            return true;
        }
    }
    return false;
}

void to_2(unsigned long long x,int i,int j,int k){
    do{
        k --;
        a1[i][j][k] = x % 2;
        x = x / 2;
    }while(x != 0);
}

int main(){

    int d,s,b;
    char ch;
    char tmpk;
    int tempk;
    char tmpch;
    while(scanf("%d%d%d",&d,&s,&b) && d != 0 ){
        tmpch = getchar();
        scanf("%c",&ch);

        int cnt = 0;
        for(int i = 1;i <= d;i ++){
            tmpch = getchar();
            for(int j = 1;j <= b;j ++){
                unsigned long long tmp = 0;
                for(int k = 0;k < s;k++){
                    scanf("%c",&tmpk);
                    a1[i][j][k] = tmpk;
                    if(tmpk == 'x'){
                        if(cols[cnt - 1] == i * BIG + j){
                            continue;
                        }
                        cols[cnt ++] = i * BIG + j;
                    }else{
                        tmp = tmp * 2 + (tmpk - '0');
                    }
                }
                a[i][j] = tmp;
            }
        }
        printCols();
        for(int i = 1;i <= d;i ++){
            for(int j = 1;j <= b;j ++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        tempk = (ch == 'E' ? 0 : ((1 << (s + 1)) - 1));
        for(int j = 1;j <= b;j ++){
            int tmpcnt = 0;

            for(int i = 1;i <= d;i ++){
                if(!isinCols(i,j)){
                    tmpcols[tmpcnt ++] = i;
                }
            }
            int tmpi = a[tmpcols[0]][j];
            for(int i = 1;i < tmpcnt;i ++){
               // printf("%d ",a[tmpcols[i]][j]);
                tmpi = tmpi ^ a[tmpcols[i]][j];
            }
            cout<<tmpcnt<<endl;
            if((d - tmpcnt) > 1){
                cout<<"Invaild"<<endl;
            }else if((d - tmpcnt) == 1){
                a[tmpcols[0]][j] = tmpi ^ tempk;
                to_2(a[tmpcols[0]][j],tmpcols[0],j,s);
            }else{
                if(tmpi != tempk){
                    cout<<"InVaild"<<endl;
                }
            }
        }
//        //直接将10进制转换成16进制(在这儿遇到问题)
//        for(int j = 1; j <= b; j ++)
//        {
//            for(int i = 1; i <= d; i++)
//            {
//                for(int k = 0; k < s; k ++)
//                {
//                    printf("%c ",a1[i][j][k]);
//                }
//                printf("\n");
//            }
//        }
        int tmpcnt = 0;
        int tmpdata = 0;
        for(int j = 1;j <= b;j ++){
            for(int i = 1;i <= d;i++){
                if(i % d == j % d){
                    continue;
                }
                for(int k = 0;k < s;k ++,tmpcnt ++){
                    tmpdata = tmpdata * 2 + (a1[i][j][k] - '0');
                    if(tmpcnt == 3){
                        printf("%X",tmpdata);
                        tmpcnt = -1;
                        tmpdata = 0;
                    }
                }

            }
        }
        if(tmpcnt != 3){
            tmpdata << (4 - tmpcnt);
            printf("%X",tmpdata);
        }
        printf("\n");
    }

    return 0;
}
