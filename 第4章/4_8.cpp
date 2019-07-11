/**
  * 本题本打算采用isRemain()来判断
  * 后来打算采用如果time大于某个临界值即为无解
  */

#include<stdio.h>
#include<math.h>

typedef struct{
    int a,b,c;
}stuNode;

stuNode stu[11];

void printStu(int n){
    for(int i = 1;i <= n;i ++){
        printf("%d %d %d\n",stu[i].a,stu[i].b,stu[i].c);
    }
    printf("\n");
}

int tmpa[11];
int tmpb[11];

/**
  * 返回正在沉睡中的人数
  */
int memcopy(int n){
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        tmpa[i] = stu[i].c;
        if(tmpa[i] > stu[i].a && tmpa[i] <= (stu[i].a + stu[i].b)){
            cnt ++;
        }
    }
    return cnt;
}

void resetC(int n){
    for(int i = 1;i <= n;i ++){
        stu[i].c = tmpb[i];
    }
}

/**
  * 是否在每一个人临时前有(n-1)个人陷入沉睡
  */
bool isRemain(int n,int max1)
{
    bool flg = true;
    for(int i = 0; i < max1; i ++)
    {
        int cnt = (n - memcopy(n));
        for(int j = 1; j <= n; j ++)
        {
            stu[j].c = (stu[j].c + 1) % (stu[j].a + stu[j].b);
            if(stu[j].c == 0) stu[j].c = stu[j].a + stu[j].b;
            if(tmpa[j]  != stu[j].a)
            {
                continue;
            }
            if(cnt > 1){
                flg = false;
                return false;
            }
        }
    }
    resetC(n);
    return flg;
}



int main(){
    int n;
    int max1 = 0x80000000;
    while(scanf("%d",&n) && n != 0){
        for(int i = 1;i <= n;i ++){
            scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
            tmpb[i] = stu[i].c;
            if(max1 < stu[i].a + stu[i].b){
                max1 = stu[i].a + stu[i].b;
            }
        }
        int cnt = 0;//清醒过来的人
        //if(!isRemain(n,max1)){
        int time = 0;

        while(cnt < n)
        {
            cnt = (n - memcopy(n));
            time ++;
            if(time == (1 << 20) - 1)
            {

                break;
            }
            for(int i = 1; i <= n; i ++)
            {
                stu[i].c = (stu[i].c + 1) % (stu[i].a + stu[i].b);
                if(stu[i].c == 0) stu[i].c = stu[i].a + stu[i].b;
                if(tmpa[i]  != stu[i].a)
                {
                    continue;
                }
                if(cnt >= ceil(n / 2.0))
                {
                    stu[i].c = 1;
                }
            }
           // printStu(n);
        }

        if(time == (1 << 20) - 1){
            printf("-1\n");
        }else{
            printf("%d\n",time);
        }

    }
    return 0;
}
