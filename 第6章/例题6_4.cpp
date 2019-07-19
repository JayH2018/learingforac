/**
  * 采用静态链表实现
  */

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char a[100001];
int next[100001];

int main(){
    string s;
    while(getline(cin,s)){
        strcpy(a + 1,s.c_str());
        int n = s.length();
        memset(next,0,sizeof(next));
        next[0] = 1;
        int tmpfirst = 1,tmplast;
        bool isFirst = true;
        for(int i = 1;i <= n;i ++){
            if(a[i] != '[' && a[i] != ']'){
                next[i] = i + 1;
            }else if(a[i] == '[' && isFirst){
                next[0] = i;
                next[i] = i + 1;
                tmplast = i - 1;
                isFirst = false;
            }else if(a[i] == '[' && !isFirst){
                next[0] = i;
                next[i] = i + 1;
                next[i - 1] = tmpfirst;
                tmpfirst = tmplast + 1;
            }else if(a[i] == ']'){
                next[i - 1] = tmpfirst;
                next[i] = i + 1;
                next[tmplast] = i;
            }
        }
        int i = 0;
        while(a[next[i]] != '\0'){
            if(a[next[i]] != '[' && a[next[i]] != ']'){
                cout<<a[next[i]];
            }
            i = next[i];
        }
        cout<<endl;


    }
    return 0;
}
