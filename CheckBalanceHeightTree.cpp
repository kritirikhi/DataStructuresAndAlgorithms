#include <iostream>
using namespace std;

// class to create a node of the binary tree
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

// building of the tree taking input from the user and connecting the nodes 
node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

class Pair{
public:
    int height;
    bool valid;
};

Pair checkBalance(node* root){
    Pair p;
    if(root==NULL){
        p.height=0;
        p.valid=true;
        return p;
    }
    
    Pair ls=checkBalance(root->left);
    Pair rs=checkBalance(root->right);
    
    p.height=max(ls.height,rs.height)+1;
    if(abs(ls.height-rs.height)<=1 && ls.valid && rs.valid){
        p.valid=true;
    }
    else{
        p.valid=false;
    }
    return p;
    
}

int main() {
    node* root=buildTree();
    Pair P=checkBalance(root);
    if(P.valid){
        cout<<"Balanced Height Tree"<<endl;
    }
    else{
        cout<<"Not Balanced Height Tree"<<endl;
    }
	return 0;
}
