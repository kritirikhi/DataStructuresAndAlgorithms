//                                            LevelOrder ZIGZAG Print (print level 1 from left to right, level 2 from right to left and so on)
#include <iostream>
using namespace std;


class node{
public:
    string data;
    node*left;
    node*right;

    node(string d){
        data=d;
        left=right=NULL;
    }
};

node* build(){
    string d;
    cin>>d;

    if(d=="false"){
        return NULL;
    }
    if(d=="true"){
        cin>>d;
    }
    node* root=new node(d);
    root->left=build();
    root->right=build();
    return root;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}

void printKthLevel(node* root,int k,int checker){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    if(checker%2==0){
        printKthLevel(root->right,k-1,checker);    
        printKthLevel(root->left,k-1,checker);
    }
    else{
        printKthLevel(root->left,k-1,checker);
        printKthLevel(root->right,k-1,checker);
    }
}

void printLevels(node* root){
    int h=height(root);

    for(int i=1;i<=h;i++){
        printKthLevel(root,i,i);
    }
}

int main() {
    node *root=build();
    printLevels(root);
    
}
