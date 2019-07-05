#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;
#define maxn 201

char src[maxn];
char des[maxn];
int guess[maxn];
int wrong;

int main(){
    while(scanf("%s%s",src,des)){
        memset(guess,0,sizeof(guess));
        int len_des = strlen(des);
        int len_src = strlen(src);
        string strsrc = string(src);
        int wrong = 0;
        bool flg = true;
        for(int i = 0;i < len_des;i++){
            if(wrong >= 6){ //边界值经常容易搞错，我在之前曾经写成wrong>6
                puts("You lose");
                flg = false;
                break;
            }
            if(guess[des[i]] == 1){
                wrong ++;
                continue;
            }
            if(strsrc.find(des[i]) == string::npos){
                wrong ++;
            }else{
                guess[des[i]] = 1;
            }
        }
        if(!flg){
            continue;
        }
        bool flg1 = true;
        for(int i = 0;i < len_src;i ++){
            if(guess[src[i]] == 0){
                flg1 = false;
                puts("You chickened out");
                break;
            }
        }
        if(flg1){
            puts("You win");
        }
    }
    return 0;
}

