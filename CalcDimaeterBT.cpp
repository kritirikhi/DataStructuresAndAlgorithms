// to find the diameter of the binary tree
//      => diameter is the longest distance between any two nodes of the tree

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

// building og the tree taking input from the user and connecting the nodes 
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

// func returns the height of the tree
int height(node* root){
    if(root==NULL){
        return 0;
    }

    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}

// there are three options to calc the diameter 
//      option1 => calc heights of left subtree and right subtree and sum of these heights gives the diameter which includes root node of the tree
//      option2 => calc height of left subtree only
//      option3 => calc height of right subtree only
// the max diameter of the three options is the final diameter of the binary tree

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    // computing heights of left and right subtrees for the option 1
    int h1=height(root->left);
    int h2=height(root->right);
    int h=h1+h2;

    // option2
    int ls=diameter(root->left);
    
    // option3
    int rs=diameter(root->right);

    return max( h, max(ls,rs) );
}

int main() {
    node* root=buildTree();
    cout<<diameter(root);
}
