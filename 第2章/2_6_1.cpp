#include <stdio.h>
int main()
{
    int a,b,c,sum1,sum2,sum3;
    for(int a = 1;a < 4;a ++){
        for(int b = 1;b < 10;b ++){
            for(int c = 1;c < 10;c ++){
                sum1 = a * 100 + b * 10 + c;
                sum2 = sum1 * 2;
                sum3 = sum1 * 3;
                if(sum3 >= 1000 || sum2 >= 1000){
                    continue;
                }
                printf("%d %d %d\n",sum1,sum2,sum3);
            }
        }
    }
}
