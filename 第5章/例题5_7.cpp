#include<stdio.h>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#include<string.h>
using namespace std;

priority_queue<long long,vector<long long>,greater<long long> > q1;
set<long long> s1;

int arr[] = {2,3,5};

int main(){
    q1.push(1);
    s1.insert(1);
    long long x;
    long long tmp;
    int k = 0;
    while(1){
        x = q1.top();
        q1.pop();
        k ++;
        if(k == 1500){
            cout<<x<<endl;
            break;
        }
        for(int i = 0;i < 3;i ++){
            tmp = x * arr[i];
            if(!s1.count(tmp)){
                q1.push(tmp);
                s1.insert(tmp);
            }
        }
    }

    return 0;
}
