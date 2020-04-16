//                                Buliding and Printing the Binary Tree          
//                             ==========================================
// binary tree is a tree in which parent node has atmost 2 children

#include <iostream>
using namespace std;

// class node having 3 members :-
//      left pointer
//      right pointer
//      data item
class node{
public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};


// the function builds a tree by taking datta as input from user and making a recursive call on the left and right subtrees
node* buildTree(){
    int d;
    cin>>d;
    // base case
    if(d==-1){
        return NULL;
    }

    // rec case
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;

}

// prints the elements of the tree via preorder (node left right)
void printPre(node* root){
    //base case
    if(root==NULL){
        return;
    }

    // rec case
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}

// prints the elements of the tree via inorder (left node right)
void printIn(node* root){
    // base
    if(root==NULL){
        return;
    }

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

// prints the elements of the tree via postorder (left right node)
void printPost(node* root){
    // base
    if(root==NULL){
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

int main() {
    node* root=buildTree();
    cout<<"PreOrder Build Binary Tree"<<endl;
    print(root);
    cout<<endl;

    cout<<"InOrder Build Binary Tree"<<endl;
    printIn(root);
    cout<<endl;

    cout<<"PostOrder Build Binary Tree"<<endl;
    printPost(root);
    cout<<endl;

}
