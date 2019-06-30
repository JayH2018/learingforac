#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define maxn 201

double a[maxn];
char s[maxn];

void init(){
    a['C'] = 12.01;
    a['H'] = 1.008;
    a['O'] = 16.00;
    a['N'] = 14.01;
}

int main(){
    memset(a,0,sizeof(a));
    init();
    double sum;
    double temp;
    char ch;
    bool isRepeat = false;
    while(scanf("%s",s)){
        sum = 0;
        isRepeat = false;
        int len_s = strlen(s);
        for(int i = 0;i < len_s;i ++){
            temp = 0;
            if(isalpha(s[i])){
                ch = s[i];
            }
            while(isdigit(s[i])){
                temp *= 10;
                temp += (s[i++] - '0');
                isRepeat = true;
            }
            if(isRepeat){
                i --;
                isRepeat = false;
            }
            temp == 0 ? (sum += a[ch]) : (sum += (a[ch] * (temp - 1)));
        }
        printf("%lf\n",sum);
    }
    return 0;
}
