/**
  */
#include<stdio.h>
#include<iostream>
#include<deque>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;

int tmp[201];

string s[21][21];

int time[21][21];

void init(){
    memset(time,0,sizeof(time));
    for(int i = 0;i < 21;i ++){
        for(int j = 0;j < 21;j ++){
            s[i][j] = "";
        }
    }
}

deque<int> waitline;
deque<int> blockline;

char buf[1001];
int m1[21];
bool isLock;

int main(){
    int n,t1,t2,t3,t4,t5,Q;
    string str;
    while(cin>>n>>t1>>t2>>t3>>t4>>t5>>Q){
        init();
        isLock = false;
        char ch = getchar();
        int i = 0,j = 0;
        while(getline(cin,str)){
            if(str != "end"){
                if(str.find("print")) time[i][j] = t2;
                else if(str.find("=")) time[i][j] = t1;
                else if(str == "lock") time[i][j] = t3;
                else if(str == "unlock") time[i][j] = t4;
                s[i][j ++] = str;
            }else{
                i ++;
                j = 0;
            }
        }
        for(int tmpi = 0;tmpi < n;tmpi ++){
            waitline.push_back(tmpi);
            m1[tmpi] = 0;
        }
        while(!waitline.empty() || !blockline.empty()){
            int turn = waitline.front();
            waitline.pop_front();
            int tmpj = m1[turn];//当前程序执行到第j条语句
            int tmpQ = Q;
            bool needLock = false;
            while(tmpQ >= time[turn][tmpj] && time[turn][tmpj] != 0){
                tmpQ -= time[turn][tmpj];
                if(s[turn][tmpj] == "lock"){
                    if(isLock){
                        blockline.push_back(turn);
                        needLock = true;
                        break;
                    }
                    else isLock = true;
                }else if(s[turn][tmpj].find("print") != string::npos){
                    cout<< (turn + 1) << ": " << tmp[s[turn][tmpj][s[turn][tmpj].length() - 1]]<<endl;
                }else if(s[turn][tmpj].find("=") != string::npos){
                    int end1 = s[turn][tmpj].length();
                    string tmpstr = s[turn][tmpj].substr(4,end1 - 4);
                    strcpy(buf,tmpstr.c_str());
                    int tmpi = atoi(buf);
                    tmp[s[turn][tmpj][0]] = tmpi;
                }else if(s[turn][tmpj] == "unlock"){
                    int tmpturn = blockline.front();
                    blockline.pop_front();
                    waitline.push_front(tmpturn);
                    isLock = false;

                }
                needLock = false;
                m1[turn] = (++tmpj);
            }
            if(s[turn][tmpj] != "" && !needLock){
                waitline.push_back(turn);
            }
        }
    }
    return 0;
}
