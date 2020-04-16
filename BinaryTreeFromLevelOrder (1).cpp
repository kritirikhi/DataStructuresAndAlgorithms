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

void bottomView(node* root,int d,map<int,vector<int>> &m){
    if(root==NULL){
        return;
    }

    if(root->data!=-1){
        if(m.count(d)==1){
            m.erase(d);
        }
        m[d].push_back(root->data);
    }
    bottomView(root->left,d-1,m);
    bottomView(root->right,d+1,m);
}

int main() {
    vector<int> a;
    a.push_back(20);
    a.push_back(8);
    a.push_back(22);
    a.push_back(5);
    a.push_back(3);
    a.push_back(-1);
    a.push_back(25);
    a.push_back(-1);
    a.push_back(-1);
    a.push_back(10);
    a.push_back(14);
    a.push_back(-1);
    a.push_back(-1);

    node* root=NULL;
    root=buildTree(a);
    print(root);
    cout<<endl;

    map<int,vector<int>> m;
    bottomView(root,0,m);

    for(auto it=m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
             cout<<it->second[i]<<" ";
        }
    }
}
