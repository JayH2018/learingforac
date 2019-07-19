#include<stdio.h>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;

typedef struct{
    int m;
    int n;

}Matrix;

Matrix tmatrix1[31];
Matrix matrix[31];

stack<char> s1;

void clears1(){
    while(!s1.empty()){
        s1.pop();
    }
}

void arrcpy(){
    for(int i = 0;i < 31;i ++){
        matrix[i].m = tmatrix1[i].m;
        matrix[i].n = tmatrix1[i].n;
    }
}

bool SupMat(int& count1)
{
    string s;
    while(cin>>s)
    {
        arrcpy();
        count1 = 0;
        clears1();
        int tmpi = 0;
        int n = s.length();
        if(n == 1)
        {
            puts("0");
            continue;
        }
        while(tmpi < n)
        {
            switch(s[tmpi])
            {
            case '(':
                s1.push(s[tmpi]);
                break;
            case ')':
            {
                int tmpb = s1.top() - 'A';
                s1.pop();
                int tmpa = s1.top() - 'A';
                s1.pop();
                s1.pop();
                if(matrix[tmpa].n != matrix[tmpb].m){
                    puts("error");
                    clears1();
                    break;
                }
                else
                {
                    count1 += (matrix[tmpa].m * matrix[tmpa].n * matrix[tmpb].n);
                    matrix[tmpa].n = matrix[tmpb].n;
                    s1.push('A' + tmpa);
                }
            }
            break;
            default:
                s1.push(s[tmpi]);
                break;
            }
            tmpi ++;
        }
        while(!s1.empty())
        {
            if(!isalpha(s1.top()))
            {
                puts("error");
                break;
            }
            else if(s1.size() == 1)
            {
                cout<<count1<<endl;
                break;
            }
            int tmpb = s1.top() - 'A';
            s1.pop();
            int tmpa = s1.top() - 'A';
            s1.pop();
            if(matrix[tmpa].n != matrix[tmpb].m)
                return false;
            else
            {
                count1 += (matrix[tmpa].m * matrix[tmpa].n * matrix[tmpb].n);
                matrix[tmpa].n = matrix[tmpb].n;
                s1.push('A' + tmpa);
            }
        }
    }
}



int main(){
    int N;
    char ma;
    int m1,n1;
    scanf("%d",&N);
    for(int i = 0;i < N;i ++){
        char ch1 = getchar();
        scanf("%c",&ma);
        scanf("%d%d",&tmatrix1[ma - 'A'].m,&tmatrix1[ma - 'A'].n);
    }
    int count1 = 0;
    SupMat(count1);

    return 0;
}
