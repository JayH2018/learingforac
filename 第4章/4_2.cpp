#include<stdio.h>
#include<string.h>
int V[10][10];
int H[10][10];

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)){
        memset(V,0,sizeof(V));
        memset(H,0,sizeof(H));
        for(int i = 0;i < m;i ++){
            char ch = getchar();//³Ôµô»Ø³µ
            int k1,k2;
            scanf("%c%d%d",&ch,&k1,&k2);
            switch(ch){
            case 'H':
                H[k1][k2] = 1;
                break;
            case 'V':
                V[k1][k2] = 1;
                break;
            }
        }
        int tmpstep = 1;
        bool flag = true;
        while(tmpstep <= n){
            int sum = 0;
            for(int i = 1;i <= n;i += 1){
                for(int j = 1;j <= n;j += 1){
                    if(H[i][j] == 1 && H[i + tmpstep][j] == 1 && V[j][i] == 1 && V[j + tmpstep][i] == 1){
                        bool flg = true;
                        for(int k = 1; k < tmpstep;k ++){
                            if(!(H[i][j + k] == 1 && H[i + tmpstep][j + k] == 1 && V[j][i + k] == 1 && V[j + tmpstep][i + k] == 1)){
                                flg = false;
                            }
                        }
                        if(flg){
                            sum ++;
                        }
                    }
                }
            }
            tmpstep ++;
            if(sum == 0) continue;
            flag = false;
            printf("%d square (s) of size %d\n",sum,tmpstep - 1);

        }
        if(flag){
            puts("No completed squares can be found.");
        }

    }
    return 0;
}
