//          TO FIND THE LARGEST BST IN THE BINARY TREE
// we will check whether the tree is bst for every node of the binary tree
// calc the count of the nodes if the tree is BST
// simply make size=max(size,count)
#include <iostream>
#include<climits>
using namespace std;
// int size=0;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        right=left=NULL;
    }
};

node* buildTree(int preorder[],int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }

    int static j=0;
    node* root=new node(preorder[j]);
    int i;
    for(i=s;i<=e;i++){
        if(inorder[i]==preorder[j]){
            break;
        }
    }
    j=j+1;
    root->left=buildTree(preorder,inorder,s,i-1);
    root->right=buildTree(preorder,inorder,i+1,e);
    return root;
}

bool isBST(node* root,int minv=INT_MIN,int maxv=INT_MAX){
    if(root==NULL){
        return true;
    };

    if(root->data >= minv && root->data <= maxv && isBST(root->left,minv,root->data) && isBST(root->right,root->data,maxv) ){
        return true;
    }
    return false;
}

int sizeOF(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+sizeOF(root->left)+sizeOF(root->right);
}

void largestBST(node* root,int *size){
    if(root==NULL){
        return ;
    }

    if(isBST(root)){
        int count=sizeOF(root);
        *size=max(*size,count);
    }

    largestBST(root->left,size);
    largestBST(root->right,size);
}

int main() {
    int n;
    cin>>n;

    int preorder[n]; 
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    int inorder[n];
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }

    node* root=buildTree(preorder,inorder,0,n-1);

    int size=0;
    largestBST(root,&size);
    cout<<size;
}

