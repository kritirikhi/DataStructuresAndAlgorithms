// to make a balanced binary search tree from sorted array of elements
#include <iostream>
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

node* buildTree(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(a[mid]);
    root->left=buildTree(a,s,mid-1);
    root->right=buildTree(a,mid+1,e);
    return root;
}

void print(node* root){
    // base case
    if(root==NULL){
        return;
    }
    cout<< root->data <<" ";
    print(root->left);
    print(root->right);
}

int main() {
    int t;
    cin>>t;

    for(int x=0;x<t;x++){
        int n;
        cin>>n;

        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        node*root=buildTree(a,0,n-1);
        print(root);
        cout<<endl;
    }
}
