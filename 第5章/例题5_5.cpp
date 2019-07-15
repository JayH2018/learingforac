/**
  * 集合的集合
  * 本题程序的意思是如果m1 = { { {} : 0 }, { {{}} : 1} };
  * 那么{{{}}}对应的set<int> s存储的是s = (1);
  * {{}}对应的set<int> s存储的是s = (0)
  * {}对应的set<int> s是空(里面没有任何元素)
  * {{},{{}}}对应的set<int> s存储的是s = (0,1)
  */

#include<stdio.h>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

stack<int> st1;

/**
  * m1和vec1组成集合和ID的双射关系
  */
map<set<int>,int> m1;
//到底谁是key谁是value，取决于谁唯一。本题集合唯一即对应唯一的下标
//通过集合取得ID。
vector<set<int> > vec1;
//根据ID取set，ID就是下标

int ID = 0;

int getID(set<int> x){
    if(m1.count(x) != 0) return m1[x];
    int tmp = vec1.size();
    m1[x] = tmp;
    vec1.push_back(x);
    return tmp;
}


int main(){
    string tmp;
    while(cin >> tmp){
        if(tmp[0] == 'P'){
            int tmp = getID(set<int>());
            st1.push(tmp);
        }else if(tmp[0] == 'D'){
            st1.push(st1.top());
        }else if(tmp[0] == 'U'){
            int t1 = st1.top(); st1.pop();
            int t2 = st1.top(); st1.pop();
            set<int>  set1 = vec1[t1];
            set<int>  set2 = vec1[t2];
            set<int>  s1;
            set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(s1,s1.begin()));
            st1.push(getID(s1));
        }else if(tmp[0] == 'I'){
            int t1 = st1.top(); st1.pop();
            int t2 = st1.top(); st1.pop();
            set<int>  set1 = vec1[t1];
            set<int>  set2 = vec1[t2];
            set<int>  s1;
            set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(s1,s1.begin()));
            st1.push(getID(s1));
        }else{
            int t1 = st1.top(); st1.pop();
            int t2 = st1.top(); st1.pop();
            set<int>  set1 = vec1[t1];
            set<int>  set2 = vec1[t2];
            set<int>  s1 = set2;
            s1.insert(t1);
            st1.push(getID(s1));
        }
        cout<<vec1[st1.top()].size()<<endl;
    }
    return 0;
}
