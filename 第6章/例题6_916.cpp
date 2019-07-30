/**
  * 把字母看成结点,单词看成有向边
  * 欧拉路劲判断有两种情况：
  * 无向图：除了起点和终点之外，其他点的度数应该是偶数
  * 有向图：有两个这样的结点(其中一个结点的出度比入度大一，另一个结点入度比出度大一)或者没有这样的结点
  */

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int ia[201],oa[201];
int main(){
    int N;
    string str;
    while(scanf("%d",&N)){
        memset(ia,0,sizeof(ia));
        memset(oa,0,sizeof(oa));
        for(int i = 0;i < N;i ++){
            cin>>str;
            ia[str[0]] ++;
            oa[str[str.length() - 1]] ++;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        bool isFlag = true;
        for(int i = 80;i < 201;i ++){
            //printf("%d:%d\n",ia[i],oa[i]);
            if(ia[i] == oa[i] + 1){
                cnt1 ++;
                if(cnt1 == 2){
                    isFlag = false;
                    break;
                }
            }else if(ia[i] + 1 == oa[i]){
                cnt2 ++;
                if(cnt2 == 2){
                    isFlag = false;
                    break;
                }
            }else if(ia[i] != oa[i]){
                isFlag = true;
                break;
            }
        }
        if(!isFlag || (cnt1 == 1 && cnt2 == 0) || (cnt1 == 0 && cnt2 == 1) ){
            puts("NO");
        }else{
            puts("YES");
        }
    }
    return 0;
}
