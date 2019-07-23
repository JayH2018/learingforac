/**
  * 本题我一直困在如何使用中序序列和后序序列建树上：
  * 我原本是只想用first,last来分别表示a[first...last],b[first...last],借此来建树;
  * 之后总是受困于后序序列中last比first多一个
  *       f l
  * 3 2 1 4 5 7 6
  * 3 1 2 5 6 7 4
  * 这样我总是不能在a[f...l]找不到后序序列b[l];
  * 后来我打算用L1,L2,R1,R2来表示，发现依旧是这个情况
  * 然后我发现需要统计左子树的节点个数
  * 于是就有了下面这个公式：
  * T->left = buildTree(T->left,L1,mid - 1,R1,R1 + cnt - 1);
  * T->right = buildTree(T->right,mid + 1,L2,R1 + cnt,R2 - 1);
  */


#include<stdio.h>
#include<sstream>
#include<iostream>
using namespace std;
typedef struct Node{
    int value;
    Node* left;
    Node* right;
}TreeNode;

TreeNode Tree[10001];

int a[10001];
int b[10001];
int loc;
Node* create(){
    Tree[loc].left = Tree[loc].right = NULL;
    return &Tree[loc++];
}

int retMid(int key,int first,int last){
    for(int i = first;i <= last;i ++){
        if(a[i] == key) return i;
    }
    return -1;
}
TreeNode* buildTree(TreeNode* T,int L1,int L2,int R1,int R2){
    if(L1 < 0 || L2 < 0){
        return NULL;
    }
    if(L1 == L2 || R1 == R2){
        T = create();
        T->value = a[L2];
        //cout<<T->value<<endl;
        return T;
    }
    int mid = retMid(b[R2],L1,L2);
    T = create();
    T->value = a[mid];
    int cnt = mid - L1;//左子树节点数
    //cout<<T->value<<endl;
    T->left = buildTree(T->left,L1,mid - 1,R1,R1 + cnt - 1);
    T->right = buildTree(T->right,mid + 1,L2,R1 + cnt,R2 - 1);
    return T;
}

//TreeNode* buildTree(TreeNode* T,int L1,int L2,int R1,int R2){
//    if(L1 == L2){

//    }else if(R1 == R2){
//        T = create();
//        T->value = b[R2];
//        cout<<T->value<<endl;
//        return T;
//    }
//    int mid = retMid(b[R2],L1,L2);
//    T = create();
//    T->value = a[mid];
//    cout<<T->value<<endl;
//    T->left = buildTree(T->left,L1,mid - 1,R1,mid - 1);
//    T->right = buildTree(T->right,mid + 1,L2,mid,R2 - 1);
//    return T;
//}


//TreeNode* buildTree(TreeNode* T,int first,int last){
//    if(first >= last){
//        T =create();
//        T->value = b[first];
//        cout<<T->value<<endl;
//        return T;
//    }
//    int mid = retMid(b[last],first,last);
//    T = create();
//    T->value = a[mid];
//    cout<<T->value<<endl;
//    T->left = buildTree(T->left,first,mid - 1);
//    if(mid == last - 2){
//        mid = last - 2;
//    }
//    T->right = buildTree(T->right,mid,last - 1);
//
//    return T;
//}

int min1 = 0x7fffffff;

int minleaves;

void  preOrder(TreeNode* T,int value){
    if(T == NULL) return;
    if(T->left == NULL && T->right == NULL){
        if(value + T->value < min1){
            minleaves = T->value;
            min1 = value + T->value;
        }else if(value + T->value == min1 && T->value < minleaves){
            minleaves = T->value;
        }
        return;
    }
    value += T->value;
    preOrder(T->left,value);
    preOrder(T->right,value);

}



int main(){
    bool isFirst = true;
    TreeNode *T;
    string str;
    while(getline(cin,str)){
        stringstream sst(str);
        loc = 0;
        int cnt = 0;
        int value = 0;
        if(isFirst){
            while(sst >> a[cnt++]);
            isFirst = false;
        }else{
            while(sst >> b[cnt++]);
            T = buildTree(T,0,cnt - 2,0,cnt - 2);
            preOrder(T,value);
            cout<<minleaves<<endl;
            isFirst = true;
        }
    }
    return 0;
}
