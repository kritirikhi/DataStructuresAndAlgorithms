//                                                              LADDERS PROBLEM  
// there are n steps and a boy is on the ground floor. He has to reach at the top (nth step) 
// calculate the no of ways to reach the nth step and the boy can take at max k steps from the ith step


// This approach works in O(n+k)
// int the DP array,
//      dp[0]=dp[1]=1;
//      for every ith index from 2 to k dp[i]=dp[i-1]*2;
//      for every ith index from k+1 to n dp[i] = dp[i-1] - dp[i-k-1] + dp[i-1]
//                                              = 2 * dp[i-1] - dp[i-k-1]

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calcWays(int a[],int n,int k){
    int dp[100]={0};
    // base case
    dp[0]=dp[1]=1;


    //calculating dp[i] from index 2 to k
    for(int j=2;j<=k;j++){
        dp[j]=2*dp[j-1];        
    }
    
    //calculating dp[i] from index k+1 to n
    for(int i=k+1;i<=n;i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    
    return dp[n];
    
}

int main() {
    int n,k;
    cin>>n>>k;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<calcWays(a,n,k);
	return 0;
}
