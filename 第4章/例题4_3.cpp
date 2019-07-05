#include<stdio.h>
#include<string.h>
#define maxn 21

int p[maxn];
int left; // 剩余的人

//返回最终的p
int goStep(int s,int d,int n,int t){
    for(int i = 1;i < t;){
        if(p[s] == 1){
            i ++;
        }
        s = (s + d + n - 1) % n + 1;  
    }
    while(p[s] == 0){
        s = (s + d + n - 1) % n + 1;
    }
    return s;
}
/**
  * s = (s + d + n - 1) % n + 1
  * 当d = 1时 s = (s + 1 + n - 1) % n + 1 = (s + n) % n + 1
  *      主要注意边界值n 当s = n时,执行s = (n + n) % n + 1 = 1
  * 当d = -1时 s = (s - 1 + n - 1) % n + 1 = (s + n - 2) % n + 1
  *      主要注意边界值n 当s = 1 时,执行s = (1 + n - 2) % n + 1 = n
  */
int main(){

    int n,k,m;
    int s,e;
    while(scanf("%d%d%d",&n,&k,&m)){
        s = 1;
        e = n;
        left = 0;
        for(int i = 1;i < maxn;i++){
            p[i] = 1;
        }
        bool flg = true;
        while(left < n){
            s = goStep(s,1,n,k);
            e = goStep(e,-1,n,m);
            if(s % n != e % n){
                p[s] = 0;
                p[e] = 0;
                left += 2;
                if(flg){
                    printf("%d %d",s,e);
                }else{
                    printf(",%d %d",s,e);
                }

            }else{
                p[s] = 0;
                left ++;
                if(flg){
                    printf("%d",s);
                }else{
                    printf(",%d",s);
                }
            }
            flg = false;
        }
        printf("\n");
    }

    return 0;
}

