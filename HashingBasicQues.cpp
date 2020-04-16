//                  QUESTIONS ON HASHING
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    // q1 To find the number of pairs which sum upto zero
    //=============================================================================
    // int a[6]={1,4,-1,2,-1,-2};
    // int n=6;
    // unordered_map<int,int> m;
    // for(int i=0;i<n;i++){
    //     m[a[i]]=1;
    // }

    // int count=0;
    // for(int i=0;i<n;i++){
    //     if(m.count(-a[i])==1){
    //         count++;
    //     }
    // }

    // cout<<count/2;

    // q2 to find union and intersection of 2 arrays
    ///==================================================================

    // int a[6]={1,2,3,1,4,1};
    // int b[6]={2,3,7,8,9,6};
    // int n=6;
    // unordered_map<int,int> m;

    // cout<<"intersection of 2 arrays is ";
    // for(int i=0;i<n;i++){
    //     m[a[i]]=1;
    // }
    // for(int i=0;i<n;i++){
    //     if(m[b[i]]){
    //         cout<<b[i]<<" ";
    //     }
    // }
    // cout<<endl;

    // cout<<"union of 2 arrays is ";
    // for(int i=0;i<n;i++){
    //     m[b[i]]=1;
    // }
    // for(auto x:m){
    //     cout<<x.first<<" ";
    // }

    // q3 remove duplicates from the array
    // int a[6]={1,3,2,2,2,1};
    // int n=6;
    // unordered_map<int,int> m;
    // for(int i=0;i<n;i++){
    //     m[a[i]]=1;
    // }

    // for(auto x:m){
    //     cout<<x.first<<" ";
    // }

    // q4 to remove cycle from the link list
    // for this we will make hashtable node to consist <node*,bool> node* is the address of the node of the link list
    // bool checks whether the node already present in the link list or not
    // if any node points to the address of the node already present in he link list then cycle exists
} 
