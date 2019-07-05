#include<stdio.h>
#include<string.h>
#define maxn 1001

char buf1[maxn];
char buf2[maxn];

char code[8][1 << 8];

void init(char buf[],int len){
    int cnt = 0;
    for(int i = 1;;i ++){
        for(int j = 0;j < 2 * i - 1;j ++){
            code[i][j] = buf[cnt ++];
            if(cnt >= len){
                return;//return的适当使用可以直接跳过两层循环
            }
        }
    }
}
char readchar(){
    char ch = getchar();
    while(ch == '\r' || ch == '\n'){
        ch = getchar();
    }
    return ch;
}

char readcodes(int len,bool& isPassed,bool &isRepeat){
    int sum = 0;
    for(int i = 0;i < len;i ++){
        char ch = readchar();
        sum = sum * 2 + (ch - '0');
    }
    if(sum == ((1 << len) - 1)){ //((1 << len) - 1)与(1 << len - 1)有区别。在拿不定优先级的情况下别怕用符号
        isPassed = false;
        isRepeat = true;
        return '0';
    }
    isPassed = true;
    return code[len][sum];
}

int readint(int len,bool &isPassed){
    if(isPassed){
        return len;
    }
    int sum = 0;
    for(int i = 0;i < 3;i ++){
        char ch = readchar();
        sum = sum * 2 + ch - '0';
    }
    return sum;
}

int main(){
    while(scanf("%s",buf1)){
        char ch = getchar();//为了吃掉回车
        init(buf1,strlen(buf1));
        int it = 0;
        bool isPassed = false; //isPassed是确保在读取小节结束码(11...1)之后才读取(以三位二进制编码表示的)编码长度
        bool isRepeat = false; //isRepeat布尔变量是为了控制是否打印ch
        //曾经尝试使用一个布尔变量同时完成isPassed与isRepeat的功能，结果发现根本做不到
        while((it = readint(it,isPassed)) != 0){
            ch = readcodes(it,isPassed,isRepeat);
            if(isRepeat){
                isRepeat = false;
                continue;
            }else{
                printf("%c",ch);
            }

        }
        printf("\n");
    }
    return 0;
}

