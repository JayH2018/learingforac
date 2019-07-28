/**
  * 四分树的字符串比较难以计算，因此采用一个二维数组记录黑色像素点和白色像素点的分布情况
  * 因此将四分树改换成二维数组，之后将两个二维数组相与得到最终结果
  */

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;


int buf[101][101];
int buf2[101][101];

void draw(int r,int c,int& key1,string str,int w){
    if(w == 0){
        return;
    }
    char ch = str[key1];
    if(str[key1] == 'f'){
        for(int i = r;i < r + w;i ++){
            for(int j = c;j < c + w;j ++){
                buf[i][j] = 1;
            }
        }
    }else if(str[key1] == 'p'){
        draw(r,c + w / 2,(++key1) ,str,w / 2);
        draw(r,c,(++key1),str,w / 2);
        draw(r + w / 2,c,(++key1),str,w / 2);
        draw(r + w / 2,c + w / 2,(++key1),str,w / 2);
    }
}


int main(){
    string str1,str2;
    int key;
    while(cin>>str1>>str2){
        memset(buf,0,sizeof(buf));
        memset(buf2,0,sizeof(buf2));
        key = 0;
        draw(0,0,key,str2,32);
        memcpy(buf2,buf,sizeof(buf));
        memset(buf,0,sizeof(buf));
        key = 0;
        draw(0,0,key,str1,32);

        int sum1 = 0;
        for(int i = 0;i < 32;i ++){
            for(int j = 0;j < 32;j ++){
                buf[i][j] = buf[i][j] | buf2[i][j];
                sum1 += buf[i][j];
            }
        }
        printf("%d\n",sum1);
    }
    return 0;
}
