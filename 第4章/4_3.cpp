#include<stdio.h>
#include<string.h>
#define BIG 100

int maze[9][9];

int Ws[BIG + 1];

int Bs[BIG + 1];

char buf[BIG + 1];

int go[][2] =
{
    0,1,
    0,-1,
    1,0,
    -1,0,
    1,1,
    1,-1,
    -1,1,
    -1,-1,
};

void printMaze()
{
    for(int i = 1; i < 9; i ++)
    {
        for(int j = 1; j < 9; j ++)
        {
            switch(maze[i][j])
            {
            case 0:
                putchar('-');
                break;
            case 1:
                putchar('W');
                break;
            case -1:
                putchar('B');
                break;
            }
        }
        printf("\n");
    }
}

int cntB = 0;
int cntW = 0;
/**
 * 自己统计有多少白子有多少红子实在又累有麻烦
 * 让电脑统计最好
 */
void statCnt()
{
    memset(Ws,0,sizeof(Ws));
    memset(Bs,0,sizeof(Bs));
    cntB = 0;
    cntW = 0;
    for(int i = 1;i < 9;i ++){
        for(int j = 1;j < 9;j ++){
            switch(maze[i][j]){
            case 1:
                Ws[cntW ++] = i * BIG + j;
                break;
            case -1:
                Bs[cntB ++] = i * BIG + j;
                break;
            }
        }
    }
}

//C1己方棋子C2对方棋子
void mvChess(char buf[],int &cnt,int C1s[],int C2s[],int C1,int C2,char &owner)
{
    bool flg  = true;
    if(buf[0] == 'L')  //buf作为参数传过来
    {
        for(int i = 0; i < cnt; i ++) //cntW改为cnt
        {
            for(int j = 0; j < 8; j ++) //Ws作为数组元素参数传过来
            {
                int tmpi = C1s[i] / BIG;
                int tmpj = C1s[i] % BIG;
                tmpi += go[j][0];
                tmpj += go[j][1];
                if(maze[tmpi][tmpj] == 0 || maze[tmpi][tmpj] == C1) continue; //常数1作为参数传过来
                while(maze[tmpi][tmpj] == C2)  ////常数-1作为参数传过来
                {
                    tmpi += go[j][0];
                    tmpj += go[j][1];
                }
                if(maze[tmpi][tmpj] == 0 && tmpi > 0 && tmpi < 9 && tmpj > 0 && tmpj < 9)
                {
                    printf("(%d,%d)",tmpi,tmpj);
                    flg = false;
                }
            }
        }
        if(flg){
            printf("No Legal Move!");
            owner = (C1 == 1 ? 'B' : 'W');

        }
        printf("\n");
    }
    else if(buf[0] == 'M')
    {

        int tmpi = buf[1] - '0';
        int tmpj = buf[2] - '0';
        maze[tmpi][tmpj] = C1;

        for(int i = 0; i < 8; i ++)
        {
            int tempi = tmpi;
            int tempj = tmpj;
            tempi += go[i][0];
            tempj += go[i][1];
            if(maze[tempi][tempj] == 0 || maze[tempi][tempj] == C1) continue; //1作为参数传过来
            while(maze[tempi][tempj] == C2)  //-1作为参数传过来
            {
                tempi += go[i][0];
                tempj += go[i][1];
            }
            if(maze[tempi][tempj] == C1)  // 1作为参数传过来
            {
                while(tempi != tmpi || tempj != tmpj)
                {
                    tempi -= go[i][0];
                    tempj -= go[i][1];
                    maze[tempi][tempj] = C1;
                }
            }
        }
        statCnt();
        printf("(Black - %d White - %d)\n",cntB,cntW);//
        owner = (owner == 'W' ? 'B' : 'W');
    }
}



int main()
{
    int n;
    while(scanf("%d",&n))
    {
        while(n-- > 0)
        {
            char ch;
            cntB = 0;
            cntW = 0;
            for(int i = 1; i < 9; i ++)
            {
                ch = getchar();
                for(int j = 1; j < 9; j ++)
                {
                    scanf("%c",&ch);
                    switch(ch)
                    {
                    case '-':
                        maze[i][j] = 0;
                        break;
                    case 'W':
                        maze[i][j] = 1;
                        //Ws[cntW ++] = i * BIG + j;
                        break;
                    case 'B':
                        maze[i][j] = -1;
                        //Bs[cntB ++] = i * BIG + j;
                        break;
                    }

                }

            }
            statCnt();
            ch = getchar();
            char owner;
            scanf("%c",&owner);
            while(scanf("%s",buf) && buf[0] != 'Q')
            {
                if(owner == 'W')
                {
                    mvChess(buf,cntW,Ws,Bs,1,-1,owner);
                }
                else
                {
                    mvChess(buf,cntB,Bs,Ws,-1,1,owner);
                }

            }
            if(buf[0] == 'Q')
            {
                printMaze();
            }
        }

    }
    return 0;
}
