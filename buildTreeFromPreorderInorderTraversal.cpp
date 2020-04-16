// building the binary tree from preorder and inorder traversal
// approach is to make a recursive func which takes inorder,preorder arrays and start and end var 
//      the root node is created from the 1st element of preorder array
//      the root element is checked in inorder to find the left subtree elements and right subtree elements
//      recursive call is made to make left and right subtrees
//      to keep track of preorder array and avoid backtracking make use of static var otherwise elements will repeat themselves during recursive calls

#include <iostream>
#include<queue>
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

// func which builds the tree from the traversal
node* buildTreePreIn(int pre[],int in[],int s,int e){
    static int j;
    // base case
    if(s>e){
        return NULL;
    }
    
    // rec case
    node* root=new node(pre[j]);
    int i;
    for(i=s;i<=e;i++){
        if(in[i]==pre[j]){
            break;
        }
    }
    
    j=j+1;
    root->left=buildTreePreIn(pre,in,s,i-1);
    root->right=buildTreePreIn(pre,in,i+1,e);
    return root;
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* f=q.front();
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
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
}


int main() {
    int pre[8]={1,2,3,4,8,5,6,7};
    int in[8]={3,2,8,4,1,6,7,5};
    
    node*root=buildTreePreIn(pre,in,0,7);
    bfs(root);
	return 0;
}
