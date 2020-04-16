//calculating diameter and height of the binary tree with O(N) Complexity
//method is to use BOTTOM UP APPROACH :- via PostOrder traversal

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

// making a pair class which has height and diameter as their members
// every node during postorder traversal has a pair associated with it and returns that pair for calc height and diameter of the upper node
class Pair{
public:
    int height;
    int diameter;
};

Pair diameter(node* root){
    Pair p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }

   Pair ls = diameter(root->left);
   Pair rs = diameter(root->right);

    p.height = max(ls.height,rs.height)+1;
    p.diameter = max(ls.height + rs.height , max(ls.diameter,rs.diameter) );
    return p;
}


int main() {
    node* root=buildTree();
    Pair ans=diameter(root);
    cout<<ans.diameter<<"  "<<ans.height;
}
