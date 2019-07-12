/**
 * 本题有两种思路：但是第二种我还没有理解透彻（两种思路都需要先进行排序）
 * 第一种：
 * 1) 算出每次填补到下一格子高度时所需的水的体积，然后将总体积减去当前所需水的体积
 * 2) 当填补到下一格高度时水不够或者水已经填完所有的格子
 * 第二种：
 * 1) 算出所有的水用来填补第二个格之后的高度、填补第三个格之后的高度......
 * 2) 结束条件是填补完当前格之后水的高度比下一个格子高度低
 */
#include<stdio.h>

#include<algorithm>

using namespace std;
#define velocity 100

int s[30 * 30];
/**
 * 涉及到数组的排序,数组再采用n(n >= 2)维结构就不太合适了
 */


int main(){
    int n,m;
    double wv;
    while(scanf("%d%d",&n,&m) && n != 0 && m != 0){
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                scanf("%d",&s[i * m + j]);
            }
        }
        int ck = n * m;
        sort(s,s + ck);
        scanf("%lf",&wv);
        int tmp = s[0];
        int temp;
        int i = 1;
        for(;i < (n * m);i ++){
            temp = s[i] - tmp;
            if((wv - (temp * velocity * i)) < 0 ) break;
            wv -= (temp * velocity * i);
            tmp = s[i];
        }
        double res = wv / (i * velocity) + s[i - 1];
        printf("%.2lf\n",res);

        printf("%.2lf percent of the region is under water.",(i * 100.0) / (n * m));

    }

    return 0;
}
