// replace each node in binary search tree with sum of all the nodes greater than or equal to it
#include <iostream>
using namespace std;

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

node* buildBST(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(a[mid]);
    root->left=buildBST(a,s,mid-1);
    root->right=buildBST(a,mid+1,e);
    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void replaceSum(node* root,int*sum){
    if(root==NULL){
        return ; 
    }
    
    replaceSum(root->right,sum);
    root->data=root->data+*sum;
    *sum=root->data;
    replaceSum(root->left,sum);
   
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    node* root=buildBST(a,0,n-1);

    int sum=0;
    replaceSum(root,&sum);
    print(root);
}
