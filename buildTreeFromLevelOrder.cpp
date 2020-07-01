// constructing Binary Tree from level order input
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;
    node(int d){
        data=d;
        right=left=NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;

    node* root=new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f=q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            f->left=new node(c1);
            q.push(f->left);
        }

        if(c2!=-1){
            f->right=new node(c2);
            q.push(f->right);
        }
    }

    return root;
}

void print(node* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main() {
    
    node* root=NULL;
    root=buildTree(a);
    print(root);
}