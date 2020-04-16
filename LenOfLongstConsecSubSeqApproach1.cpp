#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int calLen(int a[],int n,int maximum,int minimum){
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    
    int ans=0;
    int count=0;
    for(int i=minimum;i<=maximum;i++){
        if(m[i]>0){
            count++;
        }
        else{
            ans=max(ans,count);
            count=0;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    
    int a[n];
    int maximum=INT_MIN;
    int minimum=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maximum=max(maximum,a[i]);
        minimum=min(minimum,a[i]);
    }
    
    int longestSubseqLen=calLen(a,n,maximum,minimum);
    cout<<longestSubseqLen;
	return 0;
}
