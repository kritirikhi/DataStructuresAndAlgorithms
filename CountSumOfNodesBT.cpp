// to count the no of nodes in binary tree and count the sum of nodes
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

// func which returns the count of the nodes of the BT
// works recursively 
//      left subtree returns the count of the nodes in the left subtree
//      right subtree returns the count of the nodes in the right subtree
//      final count = 1 + countOfLeftSubtree + countOfRightSubtree
int countNodes(node* root){
    if(root==NULL){
        return 0;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumOfNodes(node* root){
    if(root==NULL){
        return 0;
    }

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);

}

int main() {
    node* root=buildTree();
    cout<<"No of nodes in the tree are: "<<countNodes(root)<<endl;
    cout<<"Sum of nodes in the tree are: "<<sumOfNodes(root)<<endl;
}
