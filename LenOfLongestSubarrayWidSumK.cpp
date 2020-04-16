#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calcLen(int a[],int n,int k){
    unordered_map<int,int> m;
    int pref=0;
    int len=0;
    
    for(int i=0;i<n;i++){
        pref+=a[i];
        if(pref==k){
            len=i+1;
        }
        if(m.find(pref-k) != m.end()){
            len=max(len,i-m[pref-k]);
        }
        else{
            m[pref]=i;
        }
    }
    return len;
}

int main() {
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int k;
    cin>>k;
    
    int longestSubArrayLen=calcLen(a,n,k);
    cout<<longestSubArrayLen;
	return 0;
}
