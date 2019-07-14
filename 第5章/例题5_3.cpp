#include<iostream>
#include<sstream>
#include<ctype.h>
#include<set>
using namespace std;

char chrs[1001];

int main(){
    set<string> s1;
    string str;
    while(getline(cin,str)){

        stringstream sst(str);
        string tmp;
        while(sst >> tmp){
            for(int i = 0;i < tmp.length();i ++){
                if(!isalpha(tmp[i]) && !isalnum(tmp[i])){
                    tmp.erase(i,1);
                    i --;
                }
            }
            for(int i = 0;i < tmp.length();i ++){
                if(isalpha(tmp[i])){
                    tmp[i] = tolower(tmp[i]);
                }
            }
            s1.insert(tmp);
        }
    }
    for(set<string>::iterator it = s1.begin();it != s1.end();it ++){
        cout<<*it<<endl;
    }

    return 0;
}
