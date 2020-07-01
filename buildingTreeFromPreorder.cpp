#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

node* buildtree(node* root){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    root=new node(d);
    root->left=buildtree(root->left);
    root->right=buildtree(root->right);
    
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

int main() {
    node* root=NULL;
    root=buildtree(root);
    print(root);
}
