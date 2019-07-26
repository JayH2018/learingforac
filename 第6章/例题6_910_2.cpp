#include<stdio.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;

typedef struct Node{
    Node* left;
    Node* right;
    int weight = 0;
    int horweight;

    bool operator < (const Node& node) const{
        return this->horweight < node.horweight;
    }

    bool operator > (const Node& node) const{
        return this->horweight > node.horweight;
    }

}TreeNode;

priority_queue<TreeNode,vector<TreeNode>,greater<TreeNode> > Q;
queue<TreeNode> Q1;

int loc,loc1,loc2;
int a[100001];
TreeNode tree[1001];

TreeNode* create(){
    tree[loc].left = tree[loc].right = NULL;
    return &tree[loc++];
}

TreeNode* buildTree(TreeNode* T,int horweight){
    if(a[loc2] == -1){
        loc2 ++;
        return NULL;
    }
    T = create();
    T->weight = a[loc2++];
    T->horweight = horweight;
    T->left = buildTree(T->left,horweight - 1);
    T->right = buildTree(T->right,horweight + 1);
    return T;
}

void cenOrder(TreeNode T){
    Q.push(T);
    Q1.push(T);

    while(!Q1.empty()){
        T = Q1.front();
        Q1.pop();
        //printf("%d ",T.horweight);
        if(T.left != NULL){
            Q.push(*(T.left));
            Q1.push(*(T.left));
        }
        if(T.right != NULL){
            Q1.push(*(T.right));
            Q.push(*(T.right));
        }

    }

    T = Q.top();

    int sum2 = T.horweight;
    int sum1 = 0;

    while(!Q.empty()){
        T = Q.top();
        if(sum2 != T.horweight){
            sum2 = T.horweight;
            printf("%d ",sum1);
            sum1 = 0;
        }
        sum1 += T.weight;
        Q.pop();
    }
    printf("%d\n",sum1);
}

int main(){
    string str;
    TreeNode *root;
    while(getline(cin,str) && str != "-1" ){
        loc = 0;
        loc1 = 0;
        loc2 = 0;
        int cnt = 0;
        stringstream sst(str);
        while(sst >> a[loc1 ++]);
        root = buildTree(root,0);
        cenOrder(*root);
    }
    return 0;
}
