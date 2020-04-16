//          MIN STEPS TO ONE 
// given a number n and we have to find the minimum steps needed to make number=1 
// we can follow 3 paths :-
//      n ==> n/2
//      n ==> n/3 
//      n ==> n-1 


// we can use the top down DP for this 
//      for any n f(n) {minsteps}  = min( f(n/2),f(n/3),f(n-1) ) + 1
// as there can be overlapping subproblems hene we can memoise the things using dp array 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rec(int n,int dp[]){
    // base case
    if(n==1){
        return 0;
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    
    if(n%2==0){
        op1=rec(n/2,dp)+1;
    }
   
    if(n%3==0){
        op2=rec(n/3,dp)+1;
    }
   
    op3=rec(n-1,dp)+1;
    
    int ans=min(op1,min(op2,op3));
    return dp[n]=ans;
    
}

int main() {
    
    int n;
    cin>>n;
    
    int dp[n+1]={0};
    cout<<rec(n,dp);
	return 0;
}
