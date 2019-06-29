#include<stdio.h>
#include<math.h>

int main(){
    int n,m;
    double x,sum;
    while(scanf("%d%d",&n,&m) != 0 && n && m){
        sum = 0;
        for(double i = n;i <= m;i ++){
            x = 1 / i;
            x = x / i;
            sum += x;
        }
        printf("%.5lf\n",sum);
    }
}
