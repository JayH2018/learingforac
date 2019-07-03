#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>

using namespace std;

/**
 * 本题实质上是一个数学题。
 * m: 2进制尾数;
 * e: 2进制阶码;
 * c: 10进制尾数;
 * d: 10进制阶码;
 * 因此有如下的相等关系：m * 2^e = c * 10^d;
 * 所以(对10取对数之后有)：lg(m) + elg(2) = lg(c) + d;
 * 所以设t = lg(m) + elg(2);
 * 得：d = t - lg(c);(因为1 <= c <= 10;所以0<= lg(c) <= 1)
 * 所以d = floor(t / 1); // t / 1向下取整
 * 所以c = 10^(t - d);
 * 请注意：因为浮点数自身的误差，根本做不到精确匹配，只能做到近似匹配。本题设置误差范围再1e-5;
 * 本题举出示例：
 * 阶码6位,尾数8位.可以表示的最大浮点数为0.111111111*2^(111111)。此时一共有9位小数，
 * 这是因为用计算机表示的时候就把最前面的"0.1"这个永远不变的部分给省略掉，只表示可能变化的部分.
 * 因此e = 2^6 - 1 = 63;m = 1 - (2^(-9)) = 0.998046875;
 * 所以E[6][8] = d;(c的求法见上)
 *     M[6][8] = c;(d的求法见上)
 * 所以E[6][8] = 18,M[6][8] = 9.205357638345294;
 */

long long E[10][31];
double M[10][31];

#define minlef 1e-5

int main(){
    for(int i = 0;i < 10;i ++){
        memset(E[i],0,sizeof(E[i]));
        memset(M[i],0,sizeof(M[i]));
    }

    for(int i = 0;i < 10;i ++){
        for(int j = 1;j < 31;j ++){
            double e = (1 << j) - 1;
            double m = 1 - 1.0/(1<<(i+1));//(1 >> (i + 1))是不是与1.0/(1<<(i+1))等价
            double t = log10(m) + e * log10(2);
            E[i][j] = floor(t);
            M[i][j] = pow(10,t - E[i][j]);
        }
    }
    string s1;
    while(cin>>s1 && strcmp(s1.c_str(),"0e0") != 0){
        int mid = s1.find('e');
        double m = atof(s1.substr(0,mid + 1).c_str());
        long long e = atoll(s1.substr(mid + 1,s1.length() - mid - 1).c_str());
        bool flag = true;
        for(int i = 0;i < 10;i ++){
            for(int j = 1;j < 31;j ++){
                if(e == E[i][j] && fabs(m - M[i][j]) < minlef){
                    printf("%d %d",j,i);
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
    }
    return 0;
}
