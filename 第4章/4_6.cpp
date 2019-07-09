

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

map<char,string> m1;
multimap<string,string> dict;

char buf[1001];

string strs[1001];

char tmpbuf[1001];
char tmpbuf1[1001];

void memsetnull(){
    for(int i = 0;i < 1001;i ++){
        strs[i].clear();
    }
}

string retSmallMatch(int cnt,string tmps){
    memsetnull();
    multimap<string,string>::iterator mit = dict.find(tmps);
    for(int k = 0;k < cnt;k ++){
        strs[k] = mit->second;
    }
    sort(strs,strs + cnt);
    return strs[0];
}

string reverseAdd(char buf[]){

    if(dict.count(string(buf)) >= 1){
        return retSmallMatch(dict.count(string(buf)),string(buf));
    }
    if(strlen(buf) > 50){
        return "";
    }
    string s1 = reverseAdd(strcat(buf,"."));
    string s2 = reverseAdd(strcat(buf,"-"));
    if(s1.empty() && !s2.empty()){
        return s2;
    }else if(!s1.empty() && s2.empty()){
        return s1;
    }
    return s1 < s2 ? s1 : s2;
}

void init(){
    char ch;
    string s;
    while(cin>>ch && ch != '*'){
        cin>>s;
        m1.insert(pair<char,string>(ch,s));
    }
    while(scanf("%s",buf) && buf[0] != '*'){
        int len  = strlen(buf);
        s.clear();
        for(int i = 0;i < len;i ++){
           string tmps = m1.find(buf[i])->second;
           s += tmps;
        }
        dict.insert(pair<string,string>(s,string(buf)));
    }
    while(scanf("%s",buf) && buf[0] != '*'){
        string tmps(buf);
        int cnt = dict.count(tmps);
        if(cnt == 1){
            multimap<string,string>::iterator mit = dict.find(tmps);
            cout<<mit->second<<endl;
        }else if(cnt > 1){
            string tempstr = retSmallMatch(cnt,tmps);
            cout<<tempstr<<"!"<<endl;
        }else{
            int len = strlen(buf);
            string s1,s2,s3;
            while(len --){
                strcpy(tmpbuf1,buf);
                tmpbuf1[len] = '\0';
                if(dict.count(string(tmpbuf1)) >= 1){
                    s1 = retSmallMatch(dict.count(string(tmpbuf1)),string(tmpbuf1));
                    break;
                }
            }
            int tmplen = strlen(buf);
            strcpy(tmpbuf,buf);
            s2 = reverseAdd(tmpbuf);

            int a = tmplen - len;
            int b = tmplen - s2.length();

            if(abs(a) == abs(b)){
                s3 = s1 < s2 ? s1 : s2;
                cout<<s3<<"?"<<endl;
            }else if(abs(a) > abs(b)){
                cout<<s2<<"?"<<endl;
            }else{
                cout<<s1<<"?"<<endl;
            }


        }
    }
}

int main(){
    init();
    for(map<char,string>::iterator it = m1.begin();it != m1.end();it ++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
