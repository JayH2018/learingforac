#include<stdio.h>
#include<iostream>
using namespace std;
char buf1[6];
char buf2[6];

int main(){
    while(scanf("%s%s",buf1,buf2)){
        bool flag = true;
        for(int i = 0;i < 3;i ++){
            char ch1 = buf1[i];
            char ch2 = buf1[5 - i];
            string s1 = string(buf2);
            int indexch1 = s1.find(ch1);
            if(ch2 != buf2[5 - indexch1]){
                flag = false;
                break;
            }
        }
        if(!flag){
            puts("FALSE");
        }else{
            puts("TRUE");
        }
    }
}
