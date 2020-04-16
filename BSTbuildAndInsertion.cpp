// building and inserting the elements in binary search tree (BST)

#include <iostream>
using namespace std;

// to create the node of the BST
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

// func to insert the single element in BST
// if data<root->data then traverse the left subtree
// else traverse the right subtree
node* insertInBST(node* root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data <= root->data){
        root->left=insertInBST(root->left,data);
    }
    else{
        root->right=insertInBST(root->right,data);
    }
    return root;
}

// taking input from the user and inserting the elements in the BST one by one
node* buildBST(){
    int data;
    cin>>data;
    node* root=NULL;

    while(data!=-1){
        root=insertInBST(root,data);
        cin>>data;
    }
    return root;
}

// printing the elements by inorder traversal
void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);

}

int main() {
    node *root=buildBST();
    print(root);
}
