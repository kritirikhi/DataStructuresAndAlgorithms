// to find whether the two trees are structurally identical or not
// if the trees are identical then their root nodes will be null at the one time
// there cant be the case that when root of 1 tree is null the root of other tree is not null
// so this will be the testcase for checker
#include <iostream>
#include<cstring>
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

bool isIdentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    bool dec1=isIdentical(root1->left,root2->left);
    bool dec2=isIdentical(root1->right,root2->right);
    return dec1&&dec2;
}

int main() {
    node *root1=build();
    node*root2=build();

    if(isIdentical(root1,root2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
