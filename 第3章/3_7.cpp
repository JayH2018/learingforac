#include<stdio.h>
#include<string.h>
/**
 * 这道题主要思想是从N个DNA序列中对应字母最多的。
 * 比如
 * 1.TATGATAC
 * 2.TAAGCTAC
 * 3.AAAGATCC
 * 1、2、3三种序列中第一个字母应该选择T。
 */

char a[51][1001];
int b[201];

char chr[1001];
int main(){
    int m,n;
    char ch;
    while(scanf("%d%d",&m,&n)){
        int sum1 = 0;
        ch = getchar();
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                a[i][j] = getchar();
            }
            ch = getchar();
        }
        for(int j = 0;j < n;j ++){
            memset(b,0,sizeof(b));
            for(int i = 0;i < m;i ++){
                switch(a[i][j]){
                case 'A':
                    b['A'] ++;
                    break;
                case 'C':
                    b['C'] ++;
                    break;
                case 'G':
                    b['G'] ++;
                    break;
                case 'T':
                    b['T'] ++;
                    break;
                default:
                    printf("Wrong Answer!\n");
                }
            }
            int max1 = 0x80000000;
            if(max1 < b['A']){
                chr[j] = 'A';
                max1 = b['A'];
            }
            if(max1 < b['C']){ //我曾经写成了else if(max1 < b['C'])
                chr[j] = 'C';
                max1 = b['C'];
            }
            if(max1 < b['G']){
                chr[j] = 'G';
                max1 = b['G'];
            }
            if(max1 < b['T']){
                chr[j] = 'T';
                max1 = b['T'];
            }
        }
        for(int k = 0;k < n;k ++){
            printf("%c",chr[k]);
        }
        printf("\n");
        int sum2 = 0;
        for(int j = 0;j < n;j ++){
            for(int i = 0;i < m;i ++){
                if(chr[j] != a[i][j]){
                    sum2 ++;
                }
            }
        }
        printf("%d\n",sum2);
    }
    return 0;
}
