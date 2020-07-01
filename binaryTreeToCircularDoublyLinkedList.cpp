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
    node* n=NULL;
    if(data!=-1){
        n = new node(data);
    }

    if(q.front()->left==NULL){
        q.front()->left=n;
    }
    else{
        q.front()->right=n;
        q.pop();
    }
    if(n!=NULL){
        q.push(n);
    }
    return root;
    
}

node* buildTree(vector<int> a){
    node* root=new node(a[0]);
    queue<node*> q;
    q.push(root);

    for(int i=1;i<a.size();i++){
        root=insert(root,a[i],q);
    }
    return root;
}

node* head=NULL; node* prevNode=NULL;
void convert(node* root){
    if(root==NULL){
        return;
    }
    
    convert(root->left);
    
    if(prevNode==NULL){
        head=root;
    }
    else{
        root->left=prevNode;
        prevNode->right=root;
    }
    
    prevNode=root;
    convert(root->right);
}

node* bTreeToCList(node *root){
    if(root==NULL){
        return NULL;
    }
    
    if(root->left==NULL && root->right==NULL){
        root->left=root;
        root->right=root;
        return root;
    }
    
    convert(root);
    
    node* last;
    node* temp=head;
    while(temp!=NULL){
        last=temp;
        temp=temp->right;
    }

    last->right=head;
    head->left=last;
    return head;
}

int main() {
    string s;
    getline(cin,s);
    char* c = &s[0];
    char* s2=strtok(c," ");
    
    vector<int> a;
    while(s2){
        a.push_back(stoi(s2));
        s2=strtok(NULL," ");
    }

    node* root=NULL;
    root=buildTree(a);

    node* head1=bTreeToCList(root);

    cout<<head1->data<<" ";
    node* temp=head1;
    temp=temp->right;
    while(temp!=head1){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
cout<<endl;
    node* last=head1->left;
    cout<<last->data;
    temp=last->left;
    while(temp!=last){
        cout<<temp->data<<" ";
        temp=temp->left;
    }
    cout<<endl;
}