#include<stdio.h>
#include<algorithm>

using namespace std;

int a[10001];

int main(){
    int N,Q;
    while(scanf("%d%d",&N,&Q) && N != 0 && Q != 0){
        for(int i = 1;i <= N;i ++){
            scanf("%d",&a[i]);
        }
        int tmpk;
        int* tmp;
        for(int i = 0;i < Q;i ++){
            scanf("%d",&tmpk);
            tmp = lower_bound(a,a + N,tmpk);
            if(tmp - a == N || *tmp != tmpk){
                printf("%d not found!\n",tmpk);
            }else{
                printf("%d found at %d\n",tmpk,tmp - a + 1);
            }
        }
    }
    return 0;
}
