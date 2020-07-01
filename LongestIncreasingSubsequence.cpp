//                                                          LONGEST INCREASING SUBSEQUENCE
// given an array of elements. We have to find the length of longest increasing subsequence 
// eg a={3,10,2,1,20}   longest increasing subseq is {3,10,20} so output=3

// Approach
// In the dp array,
//      the ith state defines the len of longest 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int dp[n]={1};
    int longestIncSubseqLen=0;
    for(int i=1;i<n;i++){
        int maximum=0;
        for(int j=0;j<i;j++){
            if(a[j]<=a[i]){
                maximum=max(maximum,dp[j]);                
            }
        }
        dp[i]=maximum+1;
        longestIncSubseqLen=max(longestIncSubseqLen,dp[i]);
    }
    
    
    cout<<longestIncSubseqLen;
	return 0;
}
