#include <iostream>
#include<climits>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=right=NULL;
    }
};

node *constructBST(int pre[],int j,int n,int minv=INT_MIN,int maxv=INT_MAX){
    // base case
    if(j>=n){
        return NULL;
    }
    // static int j=0;
    //node* root=NULL;
    if(pre[j]>=minv && pre[j]<maxv){
        node* root=new node(pre[j]);
        j=j+1;
       // if(j<n){
            root->left=constructBST(pre,j,n,minv,root->data);
            root->right=constructBST(pre,j,n,root->data,maxv);
        //}
        return root;
    }
    if( !(pre[j]>=minv && pre[j]<maxv) ){
        j=j+1;
        constructBST(pre,j,n,minv,maxv);
    }
}

void print(node* root){
    // base case
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<< root->data <<"  ";
    print(root->right);
}

int main() {
    int pre[6]={1,3,5,7,6,8};
    static int j=0;
    node* root=constructBST(pre,j,6);
    print(root);
    return 0;
}

