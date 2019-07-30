#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

char buf[201][1001];

void dfs(int n,int st,int et,int cnt){
    for(int i = st;i < et;i ++){
        //cout<<buf[n][i]<<endl;
        if(!isalpha(buf[n][i])) continue;
        printf("%c(",buf[n][i]);
        if(n >= cnt) printf(")");//±ß½ç
        if(buf[n + 1][i] == '|'){
            //if(i == 0) dfs(n + 2,0,cnt);
            int j = i,k = i;
            while(buf[n + 2][j] == '-' && j > 0 ){
                //char ch = buf[n + 2][i];
                j --;
            }
            int slen = strlen(buf[n + 2]);
            while(buf[n + 2][k] == '-' && k < slen){
                k ++;
            }
            dfs(n + 3,j,k,cnt);
        }
        printf(")");
    }
}

int main(){
    int n = 0,N;
    while(scanf("%d",&N)){
        while(N--){
            n = 0;
            char ch = getchar();//吃掉回车
            while(fgets(buf[n],1001,stdin) && buf[n][0] != '#'){
                //printf("%s",buf[n]);
                n++;
            }
            printf("(");
            dfs(0,0,strlen(buf[0]),n);
            printf(")\n");
        }
    }
    return 0;
}
