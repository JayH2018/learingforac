#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 105


using namespace std;
char a[maxn];

char f[maxn];

int main(){
    while(scanf("%s",a)){
        string s = string(a);
        int k = 0;
        int oldk = 0;
        int len_a = strlen(a);
        for(int i = 3;i < len_a / 2;i ++){
            strcpy(f,s.substr(0,i).c_str());
            k = 0;
            oldk = 0 - i;
            while(s.find(f,k) != (s.length() - i) && s.find(f,k) != string::npos && ((s.find(f,k) - oldk) == i)){
                oldk = s.find(f,k);
                k += i;
            }
            if(s.find(f,k) == (s.length() - i)){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
