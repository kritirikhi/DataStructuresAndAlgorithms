// Printing the Binary Tree via LEVEL ORDER (nodes at the kth level where k = 1 - height of the tree) via BFS(Breadth First Search)

#include <iostream>
#include<queue>
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

// the function builds a tree by taking data as input from user and making a recursive call on the left and right subtrees
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

// in BFS
//      the root is pushed in the queue
//      while q is not empty
//          the front element is popped
//          the children of the popped element are pushed in the queue
void BFS(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f=q.front();
        cout<<f->data<<" ";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}

int main() {
    node* root=BuildTree();
    BFS(root);
}
