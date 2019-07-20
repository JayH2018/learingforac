/**
  * 静态链表实现双链表(L,D,R均为数组名)
  * L:  6   0 1 2 3 4 5
  * D: '\0' 1 2 3 4 5 6 '\0'
  * R:  1   2 3 4 5 6 7
  * 本题利用数组下标代替指针
  */

#include<stdio.h>
#include<iostream>
using namespace std;

int L[100001];//L[i]表示数组元素i的左边元素
int R[100001];//R[i]表示数组元素i的右边元素

char D[100001];//元素值

void init(int n)
{
    R[0] = 1;
    L[0] = n;
    D[0] = 0;
    D[n + 1] = 0;
    for(int i = 1; i <= n; i ++)
    {
        D[i] = i + '0';
    }
    for(int i = 1; i <= n; i ++)
    {
        R[i] = i + 1;
    }
    for(int i = n; i >= 1; i --)
    {
        L[i] = i - 1;
    }
}

void swaparr(int n)
{
    for(int i = 1; i < n / 2; i ++)
    {
        swap(D[i],D[n - i + 1]);
    }
    if(n % 2 == 0)
    {
        swap(D[n / 2],D[n / 2 + 1]);
    }
}

void printD()
{
    int x = 0;
    int y = 0;
    while(D[R[x]] != 0)
    {
        cout<<D[R[x]]<<" ";
        x = R[x];
    }
    cout<<endl;
    while(D[L[y]] != 0)
    {
        cout<<D[L[y]]<<" ";
        y = L[y];
    }
    cout<<endl;
}

int main()
{
    int n,m,c;
    int x,y;
    int tmpx,tmpy;
    while(scanf("%d%d",&n,&m))
    {
        init(n);
        while(m --)
        {
            scanf("%d",&c);
            if(c == 4)
            {
                swaparr(n);
            }
            else
            {
                scanf("%d%d",&x,&y);
                tmpx = x;
                tmpy = y;
                switch(c)
                {
                case 1:
                {
                    while(D[L[tmpy]] - '0' != x && D[L[tmpy]] != 0)
                    {
                        tmpy = L[tmpy];
                    }
                    if(D[L[tmpy]] != 0)
                    {
                        break;
                    }
                    else
                    {
                        R[y] = R[x];
                        L[R[x]] = L[x];
                        L[x] = 0;
                        R[x] = tmpy;
                        L[tmpy] = x;
                        R[0] = x;
                    }
                }
                break;
                case 2:
                {
                    while(D[R[tmpy]] - '0' != x && D[R[tmpy]] != 0)
                    {
                        tmpy = R[tmpy];
                    }
                    if(D[R[tmpy]] != 0)
                    {
                        break;
                    }
                    else
                    {
                        R[L[x]] = R[x];
                        L[R[x]] = L[x];
                        R[tmpy]  = x;
                        L[x] = tmpy;
                        L[0] = x;
                        R[x] = n + 1;
                    }
                }
                break;
                case 3:
                {
                    swap(D[x],D[y]);
                }
                break;
                }
            }

            printD();
        }
    }
    return 0;
}
