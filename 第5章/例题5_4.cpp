#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string.h>
#include<ctype.h>
using namespace std;

map<string,string> m1;
set<string> s1;
char buf[1001];

string tolowerstr(string str){
    string tmp = "";
    for(int i = 0;i < str.length();i ++){
        tmp += tolower(str[i]);
    }
    strcpy(buf,tmp.c_str());
    int tt = strlen(buf);
    sort(buf,buf + tt);
    string tmp1(buf);
    return tmp1;
}

int main(){
    string str;
    while(cin >> str && str != "#"){
        string tmp = tolowerstr(str);
        if(m1.count(tmp) != 0){
            if(s1.count(m1[tmp]) != 0){
                s1.erase(s1.find(m1[tmp]));
            }
            continue;
        }
        s1.insert(str);
        m1[tmp] = str;
    }
    for(set<string>::iterator it = s1.begin();it != s1.end();it ++){
        cout<<*it<<endl;
    }
    return 0;
}
