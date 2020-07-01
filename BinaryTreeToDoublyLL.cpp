//                                      CONVERTING THE BINARY TREE TO DOUBLY LINKED LIST

// Approach
// make left subtree into the doubly linked list
// attach the left subtree to the root node 
// make right subtree into the doubly linked list and attach it

// =============================================================================================================================================

// we will perform inorder traversal
// the we will maintain the prev node which will keep the track of the prev node to be attached to the current node 


#include <bits/stdc++.h>
using namespace std;

// class ndode to store the elements of the node
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


// constructing the tree
node* buildTree(int preorder[],int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }

    static int j=0;
    node* root=new node(preorder[j]);
    int i;
    for(i=s;i<=e;i++){
        if(inorder[i]==preorder[j]){
            break;
        }
    }
    j=j+1;
    root->left=buildTree(preorder,inorder,s,i-1);
    root->right=buildTree(preorder,inorder,i+1,e);
    return root;
}


// head and prev node
node* head=NULL;
node* prevNode=NULL;

// conversion
void binaryTreeToDoublyLL(node* root){
    if(root==NULL){
        return;
    }

    // traversing the left subtree
    binaryTreeToDoublyLL(root->left);
    if(prevNode==NULL){
        head=root;
    }
    else{
        root->left=prevNode;
        prevNode->right=root;
    }

    // changing the track of prev node root node 
    prevNode=root;

    // traversing the right subtree
    binaryTreeToDoublyLL(root->right);
}

// printing the tree
void print(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

// printing the doubly linked list formed finally
void doublyLL(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}

int main() {
    int n;
    cin>>n;

    int preorder[n];
    int inorder[n];

    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    // building the tree
    node* root=NULL;
    root=buildTree(preorder,inorder,0,n-1);
    
    // printing the tree
    print(root);
    cout<<endl;

    // conversion and printing the doubly linked list
    binaryTreeToDoublyLL(root);
    doublyLL(head);
}
