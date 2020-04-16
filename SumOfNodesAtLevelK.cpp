//      Print the sum of nodes at level K
// find the nodes at level k
// sum those nodes
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

node* buildTree(){
    int d;
    cin>>d;
    node* root=new node(d);

    int noc;
    cin>>noc;

    if(noc==0){
        root->right=root->left=NULL;
    }

    for(int i=1;i<=noc;i++){
        node* child=buildTree();
        if(i==1){
            root->left=child;
        }
        if(i==2){
            root->right=child;
        }
    }
    return root;
}

void NodesKthLevel(node* root,int k,int *sum){
    if(root==NULL){
        return;
    }
    if(k==0){
        *sum = *sum + root->data;
        return;
    }
    NodesKthLevel(root->left,k-1,sum);
    NodesKthLevel(root->right,k-1,sum);
}


int main() {
    node* root=buildTree(); 
    int k;
    cin>>k;
    int sum=0;
    NodesKthLevel(root,k,&sum);
    cout<<sum;
}
