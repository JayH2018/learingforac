#include<stdio.h>
#include<stack>
#include<iostream>
using namespace std;

int A[1001];

stack<int> s;
void printA(){
    for(int i = 0;i < 5;i ++){
        printf("%d",A[i]);
    }
}
bool init(int n){
    for(int i = 0;i < n;i ++){
        scanf("%d",&A[i]);
        if(A[i] == 0) return false;
    }
   // printA();
    return true;
}



int main(){
    int N;
    while(scanf("%d",&N) && N != 0)
    {
        while(1)
        {
            if(!init(N)) break;
            int a = 1;
            int b = 1;
            int i = 0;
            bool isRight = true;
            while(i < N)
            {
                if(a == A[i])  //进站后直接出站
                {
                    i ++;
                    a ++;
                }
                else if(!s.empty() && s.top() == A[i])   //出栈字母与入栈不同，栈不空且栈顶字母与出栈序列相同
                {
                    s.pop();
                    i ++;
                }
                else if(a <= N) //栈不空且栈顶字母与出栈序列不同，只能压栈
                {
                    s.push(a++);
                }
                else
                {
                    isRight = false;
                    break;
                }
            }
            puts(isRight ? "YES" : "NO");
        }

    }
    return 0;
}
