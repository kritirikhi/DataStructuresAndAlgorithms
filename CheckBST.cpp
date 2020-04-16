// To check whether the given tree is BST or not
#include <iostream>
#include <climits>
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

// at every node 3 conditions are chekced, if the three cond are true for every node then the tree is BST
//COND1
//      the data value of the node must be between max and min where 
//          max=max element from the left subtree
//          min=min element from the right subtree
//      the left subtree must be the BST
//      the right subtree must be the BST

bool isBST(node* root,int minV=INT_MIN,int maxV=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data>=minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV) ){
        return true;
    }
    return false;
}

int main() {
    node* root=buildBST();
    print(root);
    cout<<endl;
    
    if(isBST(root)){
        cout<<"the tree is bst ";
    }
    else{
        cout<<"the tree is not bst ";
    }
    return 0;
}
