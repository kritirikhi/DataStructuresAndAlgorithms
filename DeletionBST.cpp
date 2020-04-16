// deletion in Binary Search Tree
// there are 3 cases
//      if node to be deleted has 0 children
//      if node to be deleted has 1 children
//      if node to be deleted has 2 children
// CASE 1
//      delete the node and return null
// CASE 2
//      store the left or right child in temp node 
//      delete the node 
//      return temp node
// CASE 3
//      find the inorder successor of the node to be deleted (min element in the right subtree)
//      copy the data of inorder successor to the node to be deleted
//      delete the inorder successor

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

node* deleteBST(node* root,int data){
    // base case
    if(root==NULL){
        return NULL;
    }

    // searching the item in left subtree
    else if(data < root->data){
        root->left=deleteBST(root->left,data);
        return root;
    }

    // searching the item in right subtree 
    else if(data > root->data){
        root->right=deleteBST(root->right,data);
        return root;
    }

    // if item found 
    else if(data==root->data){
        // if searched item node has 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // if searched item node has 1 child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        // if searched item node has 2 children
        else{
            node* replace=root->right;
            while(replace->left != NULL){
                replace=replace->left;
            }

            root->data=replace->data;
            root->right=deleteBST(root->right,replace->data);
            return root;
        }
    }
}

int main() {
    node* root=buildBST();
    print(root);
    cout<<endl;

    int del;
    cin>>del;

    deleteBST(root,del);
    print(root);
}
