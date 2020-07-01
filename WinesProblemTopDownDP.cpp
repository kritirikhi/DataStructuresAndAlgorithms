//                                                              WINES PROBLEM (top down)
// we are given an array where the ith index gives the price of ith wine 
// We can sell exactly one wine in one year
// after every year the prices of all the wines become y times (the year going on)
// In a particular year , we can sell the wine either from the extreme left or extreme right
// find the maximum profit possible


// Approach
// in yth year we have 2 options  (i 0 to n) , j(n-1 to 0)
//      option 1   take left most wine and find the profit for the left over array 
//          op1 = a[i]*y + recursivefunc(i+1,j,y+1)
//      option 2 take the rightmost wine and find the profit for the left over array
//          op2 = a[j]*y + recursivefunc(i,j-1,y+1)
//      take the max of 2 options as ans for that subproblem
// for overlapping subpproblmes we will use 2d DP array to reduce the time complexity
// if(i>j)  then that means no wine left hence return 0 

// GENERALISATION
// F(i,j,y) = MAX( F(i+1,j,y+1),F(i,j-1,y+1) )
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int i,int j,int p[],int yrs,int dp[][100]){
    if(i>j){
        return 0;
    }
    
    // if the overlapping problem occurs then return the value already stored in DP array
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    
    // The 2 possible choices    
    int op1=p[i]*yrs + maxProfit(i+1,j,p,yrs+1,dp);
    int op2=p[j]*yrs + maxProfit(i,j-1,p,yrs+1,dp);
    
    return dp[i][j]=max(op1,op2);
}

int main() {
    
    int n;
    cin>>n;
    
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    
    int dp[100][100]={0};
    cout<<maxProfit(0,n-1,p,1,dp);
	return 0;
}
