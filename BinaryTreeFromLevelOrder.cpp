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
node* insert(node* root,int data,queue<node*> &q){
    node* n=new node(data);
    if(root==NULL){
        root=n;
    }
    else if(q.front()->left==NULL){
        q.front()->left=n;
    }
    else{
        q.front()->right=n;
        q.pop();
    }
    q.push(n);
    return root;
}

node* buildTree(vector<int> a){
    node* root=NULL;
    queue<node*> q;
    for(int i=0;i<a.size();i++){
        root=insert(root,a[i],q);
    }
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
    vector<int> a;
    int data;
    cin>>data;
    while(data!=-1){
        a.push_back(data);
        cin>>data;
    }

    node* root=NULL;
    root=buildTree(a);
    print(root);
}
