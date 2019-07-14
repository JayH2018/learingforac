#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

vector<int> pile[25];
map<int,int> m1;

void clear_above(int a){
    int n = m1.find(a) -> second;//a所在的堆
    for(vector<int>::iterator it = pile[n].begin();it != pile[n].end();it ++){
        if(*it == a){
            it ++;
            while(it != pile[n].end()){
                pile[*it].push_back(*it);
                pile[n].pop_back();
                m1[*it] = *it;
            }
            break;
        }
    }
}

void move1(int a,int b){
    int n = m1.find(a) -> second;
    vector<int>::iterator it = find(pile[n].begin(),pile[n].end(),a);
    int k = m1.find(b) -> second;
    if(n == k) return;
    for(;it != pile[n].end();it ++){
        pile[k].push_back(*it);
        m1[*it] = k;
    }
    it = find(pile[n].begin(),pile[n].end(),a);
    pile[n].erase(it,pile[n].end());
}

void printvector(int n){
    for(int i = 0;i < n;i ++){
        vector<int>::iterator it = pile[i].begin();
        cout<<i<<": ";
        while(it != pile[i].end()){
            cout<<*it<<" ";
            it ++;
        }
        cout<<endl;
    }
}

int findup(int b){
    int n = m1.find(b) -> second;
    return pile[n][pile[n].size() - 1];
}

int main(){
    int N;
    string s1;
    string tmps1,tmps2;
    int a,b;

    while(scanf("%d",&N)){
        for(int i = 0;i < N;i ++){
            pile[i].push_back(i);
            m1[i] = i;
        }
        char ch = getchar();//吃掉回车
        while(getline(cin,s1)){
            if(s1[0] == 'q') break;
            stringstream sst(s1);
            sst >> tmps1 >> a >> tmps2 >> b;
            if(tmps2 == "onto"){
                clear_above(b);
            }
            if(tmps1 == "move"){
                clear_above(a);
            }
            if(tmps2 == "over"){
                b = findup(b);
            }
            move1(a,b);
        }
        printvector(N);
    }
    return 0;
}
