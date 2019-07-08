#include<stdio.h>
#include<iostream>
using namespace std;

#define maxn 1001

int pq[maxn][4];

int a[] = {128,64,32,16,8,4,2,1};

int getmin1(int n)
{
    int min1 = 0x7fffffff;
    int tmp;
    bool flg = true;
    for(int j = 1; j < n; j ++)
    {
        for(int k = 0; k < 4; k ++)
        {
            for(int i = 7; i >= 0; i --)
            {
                if(((1 << i) & pq[j][k]) != ((1 << i) & pq[0][k]))
                {
                    tmp = k * 8 + (7 - i);
                    flg = false;
                    break;
                }
            }
            if(!flg) break;
        }
        if(tmp < min1)
        {
            min1 = tmp;
        }
    }
    return min1;

}


int main()
{
    int n;
    string s[1001];
    while(scanf("%d",&n))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d.%d.%d.%d",&pq[i][0],&pq[i][1],&pq[i][2],&pq[i][3]);
        }
        int tmp = getmin1(n);
        int num = tmp / 8;
        int num2 = tmp % 8;
        int temp = 0;
        for(int i = 0; i < num2; i ++)
        {
            temp += a[i];
        }
        if(num == 3)
        {
            printf("%d.%d.%d.%d 255.255.255.%d",pq[0][0],pq[0][1],pq[0][2],pq[0][3] & temp,temp);
        }
        else if(num == 2)
        {
            printf("%d.%d.%d.0 255.255.%d.0",pq[0][0],pq[0][1],pq[0][2] & temp,temp);
        }
        else if(num == 1)
        {
            printf("%d.%d.0.0 255.%d.0.0",pq[0][0],pq[0][1] & temp,temp);
        }
        else
        {
            printf("%d.0.0.0 %d.0.0.0",pq[0][0] & temp,temp);
        }
        printf("\n");

    }
    return 0;
}
