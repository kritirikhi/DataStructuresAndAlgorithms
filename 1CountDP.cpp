#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n,k;
    cin>>n>>k;
    
    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }
    
    long long int l=0,r=0,maxLen=INT_MIN,zeroCount=0;
    long long int subarrL,subarrR;
    
    for(r=0;r<n;r++){
        if(a[r]==0){
            zeroCount++;
        }
        
        if(zeroCount>k){
            while(zeroCount>k){
                if(a[l]==0){
                    zeroCount--;
                }
                l++;
            }
        }
        
        long long int len=r-l+1;
        if(len > maxLen){
            maxLen=len;
            subarrR=r;
            subarrL=l;
        }
    }
    
    cout<<maxLen<<endl;
    
    for(long long int i=subarrL;i<=subarrR;i++){
        a[i]=1;
    }
    
    for(long long int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
	return 0;
}
