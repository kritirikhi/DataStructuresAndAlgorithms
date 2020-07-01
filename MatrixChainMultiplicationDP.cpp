//                                                                  MATRIX CHAIN MULTIPLICATION
// Given an array of integers A representing chain of 2-D matices such that the dimensions of ith matrix is
// A[i-1] x A[i].

// Find the most efficient way to multiply these matrices together.
// Return the minimum number of multiplications needed to multiply the chain i.e the  minCost required to multiply the matrices

// Approach  (sol based upon 1 based indexing)
// the matrices can be multiplied in any order coz matrix multiplication is associative
// for eg:- 
//     A,B,C => these matrices can be multiplied as 
//                 (A)*(B*C)
//                 (A*B)*(C)
//     The matrices multiplied in different ordering will have different costs 
//     we have to find the min cost possible
    
// make a 2D DP array
// we will start filling diagonal by diagonal with r<=c (r=> row , c=>col) 
// BASE CASE 
//     the diagonal where r==c
//     r==c means only one matrix, the cost for the matrix at its place is 0
    
//     the diagonal where (c-r+1 == 2) that means there are 2 matrices
//     the no of ways to multiply 2 matrices is only 1 so cost will be x*y*z for the 2 matrices of dimensions x*y & y*z resp
    
//     for the remaining diagonals do the following
//         find the pivot point i.e where the array of matrices can be divided into 2 subarray of matrices (dividing the prob into shorter problem)
//         for (x,y)th pos the pivot point(K) varies from x to y-1 (inclusive)
        
//         for k (x to y-1)
//         dp[x][y]=min{ dp[x][k]+dp[k+1][y] + arr[x]*arr[k+1]*arr[y] }
        
        
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCost(int a[],int n){
    int dp[n+1][n+1]={0};
    
    for(int i=0;i<=n;i++){
        dp[i][0]=-1;
        dp[0][i]=-1;
    }
    
    // base case
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    
    // moving diagonal by diagonal
    for(int steps=1;steps<n;steps++){
        int r=1;int c=steps+1;
        while(c<=n){
            int minimum=INT_MAX;
            for(int k=r;k<=c-1;k++){
                int term = dp[r][k] + dp[k+1][c] + (a[r]*a[k+1]*a[c+1]);
                minimum=min(minimum,term);
            }
            dp[r][c]=minimum;
            c++;
            r++;
        }
            
    }

    return dp[1][n];
}

int main() {
    int n;
    cin>>n;
    
    vector<int> a;
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    
    cout<<minCost(a,n);
	return 0;
}
