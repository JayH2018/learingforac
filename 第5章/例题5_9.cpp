/**
  * 枚举c1,c2就是c1和c2的两层循环
  */
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
using namespace std;

string str[10001][11];
char buf[81];

map<string,int> mc1,mc2;

bool printl(int n,int m){
    for(int c2 = 1; c2 <= m; c2 ++)
    {
        for(int c1 = 1; c1 <= m; c1 ++)
        {
            if(c1 == c2) continue;
            for(int r1 = 1; r1 <= n; r1 ++)
            {
                //cout<<str[r1][c1]<<endl;
                if(!mc1.count(str[r1][c1]))
                {
                    mc1[str[r1][c1]] = r1;
                }
                else
                {
                    int r2 = mc1[str[r1][c1]];
                    if(r1 == r2) continue;
                    //cout<<str[r1][c2]<<endl;
                    //cout<<str[r2][c2]<<endl;
                    if(str[r1][c2] == str[r2][c2])
                    {
                        int tmpmin = min(r1,r2);
                        int tmpmax = max(r1,r2);
                        r1 = tmpmin;
                        r2 = tmpmax;
                        tmpmin = min(c1,c2);
                        tmpmax = max(c1,c2);
                        c1 = tmpmin;
                        c2 = tmpmax;
                        cout<<"NO!"<<endl;
                        cout<<r1<<" "<<r2<<endl;
                        cout<<c1<<" "<<c2<<endl;
                        return false;
                    }
                }
            }
        }
    }
    cout<<"YES!"<<endl;
    return true;

}

int main(){
    int n,m;
    string tmpstr;
    while(cin >> n >> m){
        char ch = getchar();
        for(int i = 1;i <= n;i ++){
            int j = 1;
            getline(cin,tmpstr);
            strcpy(buf,tmpstr.c_str());
            char *temp = strtok(buf,",");
            while(temp){
                str[i][j ++] = string(temp);
                temp = strtok(NULL,",");
            }
        }
        printl(n,m);

    }
    return 0;
}
