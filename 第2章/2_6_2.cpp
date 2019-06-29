#include <stdio.h>
int main()
{
    double i;
    for(i = 0;i != 10;i += 0.1){ //该循环是一个死循环。因为i是个double类型的数据,不可能等于10。本人尝试使用10.0或(double)10都是死循环。有一个解决方案是改写成i < 10.0
        printf("%.1f\n",i); 
    }
    return 0;
}
