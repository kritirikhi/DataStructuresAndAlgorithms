// replacing the parent node by the sum of all the chil nodes
// dont change the leaf nodes
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

//func to print the nodes in postorder
void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    print(root->right);
    cout<<root->data <<" ";
}


// recusrive func replaces the data of the parent nodes
// store root->data in temp var
// the leftSubTreeSum + rightSubTreeSum = root->data
// then return the temp + leftSubTreeSum + rightSubTreeSum
int replaceSum(node* root){
    if(root==NULL){
        return 0;
    }
    else if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int ls=replaceSum(root->left);
    int rs=replaceSum(root->right);
    
    int temp=root->data;
    root->data=ls+rs;
    
    return temp+ls+rs;
}

int main() {
    node* root=buildTree();
    print(root);
    cout<<endl;
    
    replaceSum(root);
    print(root);
    cout<<endl;
	return 0;
}
