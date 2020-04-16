#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// the left child of trie will contain 0 and right child of trie will contain 1 
class trieNode{
public:
    trieNode* right;
    trieNode* left;
};

// for a particular element of the array we will store 32 bits in the trie 
void insert(trieNode* head,int n){
    trieNode* curr=head;
    for(int j=31;j>=0;j--){
        int bit=(n>>j)&1;
        
        // traverse in ryt part if bit is 1
        if(bit==1){
            if(curr->right==NULL){
                curr->right=new trieNode();
            }
            curr=curr->right;
        }
        
        // traverse in left part if bit is 0
        else{
            if(curr->left==NULL){
                curr->left=new trieNode();
            }
            curr=curr->left;
        }
    }
}

int findMaxXorPair(trieNode* head,int element){
    trieNode* curr=head;
    int value=element;
    int currXor=0;
    
    for(int j=31;j>=0;j--){
        int bit=(value>>j) & 1;
        
        // if ith bit is 0 then for the xor to be maximum we need a number whose ith bit is 1 
        // if ith bit as 1 is found in ryt part then inc the currXor
        // else just traverse in left part
        if(bit==0){
            if(curr->right != NULL){
                currXor+=(int)pow(2,j);
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        
        // if ith bit is 1 then for the xor to be maximum we need a number whose ith bit is 0
        // if ith bit as 0 is found in left part then inc the currXor
        // else just traverse in right part
        else{
            if(curr->left != NULL){
                currXor+=(int)pow(2,j);
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
    }
    return currXor;
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    trieNode* head = new trieNode();
    int result=INT_MIN;
    for(int i=0;i<n;i++){
        insert(head,a[i]);
        int x=findMaxXorPair(head,a[i]);
        result=max(result,x);
    }  

    cout<<result;
}
