/**
  * q = {1,2,3} ... q有3个队列，队号分别为1,2,3
  * Q = {{101,102,103},{201,202},{301,302}}...Q有三个队列：其中一队{101,102,103} 二队{201,202} 三队{301,302}
  */
#include<stdio.h>
#include<queue>
#include<map>
#include<sstream>
#include<iostream>
using namespace std;

queue<int> q,Q[1001];//q存储队列的号码
map<int,int> m1;


int main(){
    int N;
    while(cin >> N){
        string str;
        int tmpi;
        char ch = getchar();
        for(int i = 0;i < N;i ++){
            getline(cin,str);
            stringstream sst(str);
            int tmp,tmpk;
            sst >> tmp;
            while(sst >> tmpk){
                m1[tmpk] = tmp;
            }
        }
        while(cin>>str){
            if(str[0] == 'E'){
                cin>>tmpi;
                if(Q[m1[tmpi]].empty()){
                    q.push(m1[tmpi]);
                }
                Q[m1[tmpi]].push(tmpi);
            }else{
                int s = q.front();
                cout<<Q[s].front()<<endl;
                Q[s].pop();
                if(Q[s].empty()){
                    q.pop();
                }
            }
        }
    }
    return 0;
}
