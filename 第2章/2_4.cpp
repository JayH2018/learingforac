#include<stdio.h>
#include<math.h>

int main(){
    int n,m;
    double x,sum;
    while(scanf("%d%d",&n,&m) != 0 && n && m){
        sum = 0;
        for(double i = n;i <= m;i ++){
            x = 1 / i;
            x = x / i; // 直接求i * i 会造成溢出，因此先求 1 / i 得到结果x,而后得到结果x / i;
            sum += x;
        }
        printf("%.5lf\n",sum);
    }
}
