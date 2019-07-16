/**
  * 排版题
  */

#include<stdio.h>
#include<queue>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string str[101][101];
vector<string> v1;
int main(){
    int N;
    int tmpi,tmpj;
    while(cin>>N){
        string temp;
        int max1 = 0x80000000;
        for(int i = 0;i < N;i ++){
            cin>>temp;
            int x1 = temp.length();
            if(max1 < x1){
                max1 = x1;
            }
            v1.push_back(temp);
        }
        sort(v1.begin(),v1.end());
        tmpj = floor(((60 - max1) * 1.0) / (max1 + 2)) + 1;
        tmpi = ceil(N * 1.0 / tmpj);
        int k = 0;
        for(int j = 0;j < tmpj;j++){
            for(int i = 0;i < tmpi;i ++){
                if(k >= N){
                    break;
                }
                string tmpstr = v1[k++];
                str[i][j] = tmpstr.append(max1 - tmpstr.length() + 2,' ');
            }
        }
        for(int i = 0;i < tmpi;i ++){
            for(int j = 0;j < tmpj;j ++){
                cout<<str[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
