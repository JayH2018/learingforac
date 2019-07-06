#include<stdio.h>
#include<string.h>
#include<iostream>
#define maxn 51

using namespace std;

int d[maxn][maxn],tmpd[maxn][maxn],ans[maxn][maxn];

int cols[maxn];

char buf[maxn];

#define BIG 100

void printd(int r,int c){
    for(int i = 1;i <= r;i ++){
        for(int j = 1;j <= c;j++){
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}

void del(char ch,int &r,int &c){
    int n;
    scanf("%d",&n);
    memset(cols,0,sizeof(cols));
    memcpy(tmpd,d,sizeof(d));
    for(int i = 0;i < n;i ++){
        int k;
        scanf("%d",&k);
        cols[k] = 1;
    }
    if(ch == 'R'){
        for(int i = 1,cnt = 1;i <= r;i ++){
            if(!cols[i]){
                for(int j = 1;j <= c;j ++){
                    d[cnt][j] = tmpd[i][j];
                }
                cnt ++;
            }
        }
        r = r - n;
    }else{
        for(int i = 1,cnt = 1;i <= c;i ++){
            if(!cols[i]){
                for(int j = 1;j <= r;j ++){
                    d[j][cnt] = tmpd[j][i];
                }
                cnt ++;
            }
        }
        c = c - n;
    }
}

void ins(char ch,int &r,int & c){
    int n;
    scanf("%d",&n);
    memset(cols,0,sizeof(cols));
    memcpy(tmpd,d,sizeof(d));
    for(int i = 0;i < n;i ++){
        int k;
        scanf("%d",&k);
        cols[k] = 1;
    }
    if(ch == 'R'){
        for(int i = 1;i <= r;i ++){
            if(cols[i]){
                for(int j = r + n;j > i;j --){
                    for(int k = 1;k <= maxn;k ++){
                        d[j][k] = d[j - 1][k];
                    }
                }
                for(int k = 1;k <= c;k ++){
                    d[i][k] = 0;
                }
            }
            //printd(r + n,c);
        }
        r = r + n;
    }else{
        for(int i = 1;i <= c;i ++){
            if(cols[i]){
                for(int j = c + n;j > i;j --){
                    for(int k = 1;k <= maxn;k ++){
                        d[k][j] = d[k][j - 1];
                    }
                }
                for(int j = 1;j <= maxn;j ++){
                    d[j][i] = 0;
                }
            }
        }
        c = c + n;
    }
}

int main(){
    memset(d,0,sizeof(d));
    for(int i = 1;i < maxn;i ++){
        for(int j = 1;j < maxn;j ++){
            d[i][j] = i * BIG + j;
        }
    }

    int r,c,n;
    int tmpr,tmpc;
    string s1;
    while(scanf("%d %d",&r,&c) && r != 0 && c != 0){
        //printd(r,c);
        scanf("%d",&n);
        for(int i = 0;i < n;i ++){
            scanf("%s",buf);
            if(buf[0] == 'E'){
                int k1,k2,k3,k4;
                scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
                swap(d[k1][k2],d[k3][k4]);
            }else if(buf[0] == 'D'){
                del(buf[1],r,c);
            }else{
                ins(buf[1],r,c);
            }
            //printd(r,c);
        }
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(int i = 0;i < maxn;i ++){
            for(int j = 0;j < maxn;j ++){
                ans[d[i][j] / BIG][d[i][j] % BIG] = i * BIG + j;
                //i * BIG + j可以推出ans[d[i][j] / BIG][d[i][j] % BIG]现在的位置
                //d[i][j]里面的值(原来的i和原来的j经计算得出的值)可以推出原来所在的位置
                //因此ans[d[i][j] / BIG][d[i][j] % BIG]存储的是d[i][j]现在的位置
            }
        }
        for(int i = 0;i < n;i ++){
            int tmpr,tmpc;
            scanf("%d%d",&tmpr,&tmpc);
            printf("Cell(%d,%d)",tmpr,tmpc);
            if(ans[tmpr][tmpc] == 0) printf("Is Gone!\n");
            else printf("has moved to(%d,%d)",ans[tmpr][tmpc] / BIG,ans[tmpr][tmpc] % BIG);
        }
    }
    return 0;
}

