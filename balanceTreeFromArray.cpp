// building a balanced height Binary Tree from a given array
// the basic approach to do this is to make a recursive func which:
//      calc the mid (index)
//      create root from a[mid]
//      call on remaining array s to mid-1 for left subtree recursively
//      call on remaining array mid+1 to e for right subtree recursively
#include <iostream>
using namespace std;

// class node containing data,left pointer and right pointer as its members
class node{
public:
    int data;
    node*left;
    node* right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

// func which creates/builds the tree from the array
node* buildTreeArray(int a[],int s,int e){
    // base case
    if(s>e){
        return NULL;
    }
    // rec case
    int mid=(s+e)/2;
    node* root=new node(a[mid]);
    root->left=buildTreeArray(a,s,mid-1);
    root->right=buildTreeArray(a,mid+1,e);
    return root;
}

// printing the elements of the tree via preorder traversal
void printTree(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int a[5]={2,3,1,4,3};
    node* root=buildTreeArray(a,0,4);
    printTree(root);
	return 0;
}
