//                                                                       Converting BST to Sorted Linked List

// we know that BST on traversing in an inorder manner yields all the elements in sorted order
// for converting BST to Sorted Linked List, traverse in an inorder manner
// we will keep the track of prevNode traversed and the head of the linked list
// obviously the head of the linked list will be the 1st node of the inorder traversal
// as we make the head, we will keep changing the prev node

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        right=left=NULL;
    }
};

node* insert(node* root,int item){
    if(root==NULL){
        node* n=new node(item);
        return n;
    }

    if(item < root->data){
        root->left=insert(root->left,item);
    }

    else{
        root->right=insert(root->right,item);
    }

    return root;
}

node* buildtree(node* root,int a[],int n){
    for(int i=0;i<n;i++){
        root=insert(root,a[i]);
    }

    return root;
}

node* head=NULL;
node* prevNode=NULL;
void bstToLL(node* root){
    if(root==NULL){
        return;
    }

    bstToLL(root->left);

    if(prevNode==NULL){
        head=root;
    }
    else{
       prevNode->right=root;
       prevNode->left=NULL; 
       root->left=NULL;
    }
    prevNode=root;

    bstToLL(root->right);
}

void print(node* root){
    if(root==NULL){
        return;
    }

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    node* root=NULL;
    root=buildtree(root,a,n);
    print(root);

    cout<<endl;

    bstToLL(root);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}
