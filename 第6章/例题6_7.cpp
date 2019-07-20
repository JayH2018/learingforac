#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>;
using namespace std;

typedef struct Node{
    bool hasValue;
    int value;
    Node* left;
    Node* right;
}TreeNode;

int loc = 0;
TreeNode Tree[257];

char buf[1001];

queue<TreeNode> Q;

TreeNode* create(){
    Tree[loc].hasValue = false;
    Tree[loc].left = Tree[loc].right = NULL;
    return &Tree[loc++];
}

void TraverseTree(TreeNode *T){
    Q.push(*T);
    while(!Q.empty()){
        TreeNode tmp = Q.front();
        if(tmp.hasValue == false){
            cout<<"nocomplete!"<<endl;
            return;
        }
        cout<<tmp.value<<" ";
        Q.pop();
        if(tmp.left != NULL) Q.push(*(tmp.left));
        if(tmp.right != NULL) Q.push(*(tmp.right));
    }
    cout<<endl;
}

void buildTree(int num,string str,TreeNode *T){
    for(int i = 0;i < str.length();i ++){
        if(str[i] == 'L'){
            if(T->left == NULL){
                T->left = create();
            }
            T = T->left;
        }else{
            if(T->right == NULL){
                T->right = create();
            }
            T = T->right;
        }
    }
    T->value = num;
    T->hasValue = true;
}

bool createTree(TreeNode *T){
    string str;
    while(getline(cin,str)){
        string num,chr,tmpstr;
        while(str.find("(") != string::npos){
            if(str.find(",") == string::npos){
                return true;
            }
            int fir = str.find("(");
            int mid = str.find(",");
            int last = str.find(")");
            num = str.substr(fir + 1, mid - fir - 1);
            chr = str.substr(mid + 1,last - mid - 1);
            str = str.substr(last + 1,str.length() - last - 1);
            buildTree(atoi(num.c_str()),chr,T);
        }
    }
    return false;
}



int main(){
    TreeNode *T;
    T = create();
    while(createTree(T)){
        TraverseTree(T);
        loc = 0;
        T = create();
    }
    return 0;
}
