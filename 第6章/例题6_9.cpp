#include<stdio.h>
using namespace std;
typedef struct Node{
    Node* left;
    Node* right;
    int weight;
    int pweight;
}TreeNode;

TreeNode Tree[1001];

int loc;

TreeNode* create(){
    Tree[loc].left = Tree[loc].right = NULL;
    Tree[loc].pweight = 0;
    Tree[loc].weight = 0;
    return &Tree[loc++];
}

int buildTree(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int sum1,sum2;
    if(a == 0){
        a = buildTree();
    }
    sum1 = a * b;
    if(c == 0){
        c = buildTree();
    }
    sum2 = c * d;

    if(a == -1 || c == -1){
        return -1;
    }

    if(sum1 != sum2){
        return -1;
    }else{
        return (a + c);
    }
}

int main(){
    int N;
    int sum;
    while(scanf("%d",&N)){
        while(N--){
            sum = buildTree();
            puts(sum == -1 ? "NO" : "YES");
        }
    }
    return 0;
}
