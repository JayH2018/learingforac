/**
  * 本题一开始走了很大的弯路,我尝试使用int&int的方式来计算
  * 但是事实上使用bit&bit的方式会好很多
  * 使用unsigned long long a[7][101]; //a[][] 存储的是第i个单元的int类型值
  * 计算实在太麻烦
  * 使用char a1[7][101][65];//a1[][][]存储的是第i个单元的第k个bit值
  * 计算比a[][]事半功倍
  */

#include<stdio.h>
#include<iostream>
unsigned long long a[7][101];
using namespace std;
#define BIG 1000

int cols[101];
char a1[7][101][65];

int tmpcols[101];

//char b[1000001][4];

void printa1(int d,int s,int b){
    for(int i = 1;i <= d;i ++){
        for(int j = 1;j <= b;j ++){
            for(int k = 0;k < s;k ++){
                printf("%c",a1[i][j][k]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

//bool isinCols(int i,int j){
//    int tmp = i * BIG + j;
//    for(int k = 0;k < 101;k ++){
//        if(cols[k] == tmp){
//            return true;
//        }
//    }
//    return false;
//}

void dealwith1(int d,int s,int b,char ch)
{
    for(int k = 0; k < s; k++)
    {
        for(int j = 1; j <= b; j ++)
        {
            int tmpcnt = 0;
            bool flg = true;
            int tmp;
            for(int i = 1; i <= d; i ++)
            {
                if(a1[i][j][k] == 'x'){
                    tmpcnt = i;
                    continue;
                }
                if(flg){
                    tmp = a1[i][j][k] - '0';
                    flg = false;
                }else{
                    tmp = tmp ^ a1[i][j][k];
                }
            }
            if(tmpcnt != 0){
                int temp = (ch == 'E' ? 0 : 1);
                a1[tmpcnt][j][k] = tmp ^ temp;
            }
        }
    }
}

bool pan1(int d,int s,int b,char ch)
{
    int tmpi = (ch == 'E' ? 0 : 1);
    for(int k = 0; k < s; k++)
    {
        for(int j = 1; j <= b; j ++)
        {
            bool flg = true;
            int tmp;
            for(int i = 1; i <= d; i ++)
            {
                if(flg){
                    tmp = a1[i][j][k] - '0';
                    flg = false;
                }else{
                    tmp = tmp ^ (a1[i][j][k] - '0');
                }
            }
            if(tmp != (tmpi)){
                return false;
            }
        }
    }
    return true;
}

bool reverseAl(int d,int s,int b)
{
    for(int k = 0; k < s; k++)
    {
        for(int j = 1; j <= b; j ++)
        {

            for(int i = 1; i <= d; i ++)
            {
                int cnt = 0;

                if(cnt > 1)
                {
                    return true;
                }
                if(a1[i][j][k] == 'x')
                {
                    cnt ++;
                }
            }
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
        //printCols();
//        for(int i = 1;i <= d;i ++){
//            for(int j = 1;j <= b;j ++){
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }

        tempk = (ch == 'E' ? 0 : ((1 << (s + 1)) - 1));
        if(reverseAl(d,s,b)){
            cout<<"Invaild"<<endl;
            continue;
        }else{
            dealwith1(d,s,b,ch);
        }
        if(!pan1(d,s,b,ch)){
            cout<<"Invaild"<<endl;
            continue;
        }
        //printa1(d,s,b);
//        for(int j = 1;j <= b;j ++){
//            int tmpcnt = 0;
//
//            for(int i = 1;i <= d;i ++){
//                if(!isinCols(i,j)){
//                    tmpcols[tmpcnt ++] = i;
//                }
//            }
//            int tmpi = a[tmpcols[0]][j];
//            for(int i = 1;i < tmpcnt;i ++){
//               // printf("%d ",a[tmpcols[i]][j]);
//                tmpi = tmpi ^ a[tmpcols[i]][j];
//            }
//            if((d - tmpcnt) > 1){
//
//            }else if((d - tmpcnt) == 1){
//                a[tmpcols[0]][j] = tmpi ^ tempk;
//                to_2(a[tmpcols[0]][j],tmpcols[0],j,s);
//            }else{
//                if(tmpi != tempk){
//                    cout<<"InVaild"<<endl;
//                }
//            }
//        }
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
        if(tmpcnt < 3 && tmpcnt > 0){
            tmpdata = tmpdata << (4 - tmpcnt);
            printf("%X",tmpdata);
        }
        printf("\n");
    }

    return 0;
}
