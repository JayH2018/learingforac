/**
  * 这题目我一开始读错了题目的意思，结果最终发现与输出示例不符合。因此出现问题了
  */

#include<stdio.h>
#include<iostream>
#include<sstream>
#include<queue>
using namespace std;

typedef struct Node{
    Node* left;
    Node* right;
    int weight = 0;
}TreeNode;

queue<TreeNode*> Q1,Q2;
int loc,loc1,loc2;
int a[100001];
TreeNode tree[1001];

TreeNode* create(){
    tree[loc].left = tree[loc].right = NULL;
    return &tree[loc++];
}

TreeNode* buildTree(TreeNode* T){
    if(a[loc2] == -1){
        loc2 ++;
        return NULL;
    }
    T = create();
    //printf("%d",a[loc2]);
    T->weight = a[loc2++];
    T->left = buildTree(T->left);
    T->right = buildTree(T->right);
    return T;
}

void cenOrder(TreeNode* T){
    Q1.push(T);
    while(!Q1.empty() || !Q2.empty()){
        int sum1 = 0;
        do{
            T = Q1.front();
            sum1 += T->weight;
            Q1.pop();
            if(T->left != NULL) Q2.push(T->left);
            if(T->right != NULL){
                Q2.push(T->right);
            }
        }while(!Q1.empty());

        printf("%d ",sum1);

        while(!Q2.empty()){
            Q1.push(Q2.front());
            Q2.pop();
        }
    }
    printf("\n");
}

int main(){
    string str;
    TreeNode *root;
    while(getline(cin,str) && str != "-1" ){
        loc = 0;
        loc1 = 0;
        int cnt = 0;
        stringstream sst(str);
        while(sst >> a[loc1 ++]);
        root = buildTree(root);
        cenOrder(root);
        printf("\n");
    }
    return 0;
}
