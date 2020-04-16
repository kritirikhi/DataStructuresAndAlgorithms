#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int k;
    cin>>n>>k;

    int a[n];
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    } 

    int oldIdx;
    int newIdx;
    int size=n;
    while(n>0 && k>0){
        oldIdx=mp[n]; 
        newIdx=size-n;
        if(oldIdx != newIdx && k>0){
            mp[a[newIdx]]=oldIdx;
            mp[n]=newIdx;
            swap(a[oldIdx],a[newIdx]);
            k--;
        }
        n--;
    }

    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }     
}
// && oldIdx<newIdx