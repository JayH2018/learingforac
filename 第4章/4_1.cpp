#include<stdio.h>
#include<string.h>
int maze[11][10];//棋盘布局

/**
 * 本题让我印象最深的就是逆向思维：
 * 原本打算通过红方车马炮帅的情况来判断是否死棋
 * 现在可以想想可以通过黑棋将军的情况来判断是否死棋
 * 大神的博客上面有设置结构体，自己应该也要想到
 *
 */

int cols[8];

int go[][2] = {
    0,0,
    1,0,
    -1,0,
    0,1,
    0,-1
};

int go2[][2] = {
    1,2,
    2,1,
    1,-2,
    -2,1.
    -1,-2,
    -2,-1,
    2,-1,
    -1,2
};

int go3[][2] = {
    1,-1,
    1,1,
    -1,1,
    -1,-1
};

#define BIG 1000

int main(){
    int n;
    int gs,ge;//对方将领所在位置
    while(scanf("%d%d%d",&n,&gs,&ge) && n != 0 && gs != 0 && ge != 0){
        memset(cols,0,sizeof(cols));
        for(int i = 1;i < 11;i ++){
            for(int j = 1;j < 10;j ++){
                maze[i][j] = 0;
            }
        }
        maze[gs][ge] = 1;
        int cnt = 0;
        for(int i = 0;i < n;i ++,cnt ++){
            char chr = getchar();
            char ch;
            int hs,he;
            scanf("%c",&ch);
            scanf("%d %d",&hs,&he);
            maze[hs][he] = ch;
            cols[cnt] = hs * BIG + he;
        }
        int limit = 0;
        for(int i = 0;i < 5;i ++){
            int tmpgs,tmpge;
            tmpgs = gs + go[i][0];
            tmpge = ge + go[i][1];
            if(tmpgs < 4 && tmpgs > 0 && tmpge < 7 && tmpge > 3){
                limit ++;
                for(int i = 0;i < cnt;i ++){
                    switch(maze[cols[i] / BIG][cols[i] % BIG]){
                    case 'G':
                        if(tmpge == cols[i] % BIG){
                            for(int i = gs + 1;i < (cols[i] % BIG);i ++){
                                if(maze[i][tmpge] > 1){
                                    break;
                                }
                            }
                            if(i == 10){
                                limit --;
                                break;
                            }
                        }
                        break;
                    case 'R':{
                        //纵向
                        bool flg = true;
                        if(tmpge == cols[i] % BIG){
                            if(gs > (cols[i] / BIG)){
                                for(int i = (cols[i] / BIG + 1);i < gs;i ++){
                                    if(maze[i][tmpge] > 1){
                                        flg = false;
                                        break;
                                    }
                                }
                            }else{
                                for(int i = gs + 1;i < (cols[i] / BIG);i ++){
                                    if(maze[i][tmpge] > 1){
                                        flg = false;
                                        break;
                                    }
                                }
                            }
                        }else if(tmpgs == cols[i] / BIG){
                            //横向
                            if(ge > (cols[i] / BIG)){
                                for(int i = (cols[i] / BIG + 1);i < ge;i ++){
                                    if(maze[tmpgs][i] > 1){
                                        flg = false;
                                        break;
                                    }
                                }
                            }else{
                                for(int i = ge + 1;i < (cols[i] / BIG + 1);i ++){
                                    if(maze[tmpgs][i] > 1){
                                        flg = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(!flg) break;
                        else{
                            limit --;
                            break;
                        }
                    }


                    case 'C':
                    {
                        int sum = 0;
                        if(tmpgs == cols[i] % BIG){
                             if(gs > (cols[i] / BIG)){
                                for(int i = (cols[i] / BIG + 1);i < gs;i ++){
                                    if(maze[i][tmpge] > 1){
                                       sum ++;
                                    }
                                }
                            }else{
                                for(int i = gs + 1;i < (cols[i] / BIG);i ++){
                                    if(maze[i][tmpge] > 1){
                                        sum ++;
                                    }
                                }
                            }
                        }else if(tmpgs == cols[i] / BIG){
                            //横向
                            if(ge > (cols[i] / BIG)){
                                for(int i = (cols[i] / BIG + 1);i < ge;i ++){
                                    if(maze[i][tmpge] > 1){
                                       sum ++;
                                    }
                                }
                            }else{
                                for(int i = ge + 1;i < (cols[i] / BIG + 1);i ++){
                                    if(maze[i][tmpge] > 1){
                                        sum ++;
                                    }
                                }
                            }
                        }
                        if(sum == 1){
                            limit --;
                        }
                    }
                        break;
                    case 'H':
                    {
                        bool flag = true;
                        for(int i = 0;i < 8;i ++){
                            int tempgs = gs + go[i][0];
                            int tempge = ge + go[i][1];
                            if(tempgs == cols[i] / BIG && tempge == cols[i] % BIG){
                                for(int i = 0;i < 4;i ++){
                                    int mids = gs + go[i][0];
                                    int mide = ge + go[i][1];
                                    if(mids < 1 || mids > 10 || mide < 1 || mide > 9){
                                        continue;
                                    }
                                    if(maze[mids][mide] > 1){
                                        flag = false;
                                        break;
                                    }
                                }
                                if(flag){
                                   limit --;
                                }
                            }

                        }
                    }
                    }
                }
            }
        }
        if(limit <= 0){
            puts("YES");
        }else{
            puts("NO");
        }
    }
}
