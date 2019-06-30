#include<stdio.h>
#include<string.h>

int main(){
    char str[105];
    int tot = 0,sum = 0;
    while(scanf("%s",str)){
        int strlen1 = strlen(str);
        tot = 0;
        sum = 0;
        for(int i = 0;i < strlen1;i ++){
            str[i] == 'O' ? tot++ : (tot = 0);
            sum += tot;
        }
        printf("%d\n",sum);
    }
    return 0;
}
