/**
  * 通过DFS来求连通块
  */

#include<stdio.h>
#include<iostream>
using namespace std;

char maze[101][101];

int go[][2] = {
    1,0,
    -1,0,
    0,1,
    0,-1,
    1,1,
    1,-1,
    -1,1,
    -1,-1
};

int n,m;

bool dfs(int r,int c){

    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    if(maze[r][c] == '*') return false;
    else{
        maze[r][c] = '*';
    }
    for(int i = 0;i < 8;i ++){
        dfs(r + go[i][0],c + go[i][1]);
    }
    return true;
}

int main(){

    while(scanf("%d%d",&n,&m) && n != 0 && m != 0){
        for(int i = 0;i < n;i ++){
            char ch = getchar();
            for(int j = 0;j < m;j ++){
                scanf("%c",&maze[i][j]);
            }
        }
        int sum2  = 0;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(dfs(i,j)) sum2 ++;
            }
        }
        printf("%d\n",sum2);
    }
    return 0;
}
