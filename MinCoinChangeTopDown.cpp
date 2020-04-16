//                                                      MIN COIN CHANGE PROBLEM
// Given an amount n, we have to find min no of coins/notes for change of that amount


// for m coins 
//      the min no change = min( f(n-coins[i]) ) for all i (1 to m) provided that (n-coins[i]>=0)
//      to avoid the overlapping subproblems we will make a dp array to memoise the things 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCoinChange(int n,int coins[],int m,int dp[]){
    if(n==0){
        return 0;
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ans=INT_MAX;
    for(int i=0;i<m;i++){
        if(n-coins[i]>=0){
            int option=minCoinChange(n-coins[i],coins,m,dp);
            ans=min(ans,option+1);
        }
    }
    return dp[n]=ans;
}

int main() {
    
    int coins[]={1,7,10};    
    
    int n;
    cin>>n;
    
    int dp[1000]={0};
    int m=sizeof(coins)/sizeof(int);
    cout<<minCoinChange(n,coins,m,dp);
	return 0;
}
