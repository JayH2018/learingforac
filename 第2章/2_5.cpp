#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%.*lf\n",c,1.0*a/b);//程序的核心所在
    return 0;
}
