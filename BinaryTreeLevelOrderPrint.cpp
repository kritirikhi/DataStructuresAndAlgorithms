// Printing the Binary Tree via LEVEL ORDER (nodes at the kth level where k = 1 - height of the tree)

#include <iostream>
using namespace std;

// class node having 3 members :-
//      left pointer
//      right pointer
//      data item
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

// the function builds a tree by taking datta as input from user and making a recursive call on the left and right subtrees
node* BuildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node*root=new node(d);
    root->left=BuildTree();
    root->right=BuildTree();
    return root;
}

// the func calc the height of the tree from root till the max depth 
// func works recursively
// for the current root node the height = max(leftSubTreeHeight,rightSubTreeHeight) + 1
int height(node* root){
    if(root==NULL){
        return 0;
    }

    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}

// the func prints all the nodes present at level k of tree
void printKthLevel(node* root,int k){
    if(root==NULL){
        return;
    }
    else if(k==1){
        cout<<root->data<<" ";
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}


// the func prints all the nodes of the tree level by level iteratively
void printAllLevels(node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
}

int main() {
    node* root=BuildTree();
    printAllLevels(root);
}
