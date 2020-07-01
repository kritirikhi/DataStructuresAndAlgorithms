//                                                          OPTIMAL GAME STRATEGY PROBLEM

// Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

// Input Format
// First line contains the number of coins 'n'.
// Second line contains n space separated integers where ith index denotes the value of ith coin.

// Constraints
// 1 < N <= 10000 , N is always even
// 0 <= Ai <= 1000000

// Output Format
// Print a single line with the maximum possible value that Piyush can win with.

// Sample Input
// 4
// 1 2 3 4
// Sample Output
// 6
// Explanation
// Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases Piyush picks coin 2 and wins with a total of 6.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long  dp[10005][10005]={0};

long long int MaxPointsToWin(long long int a[],long long int i,long long int j){
	if(i>j){
		return 0;
	}

	if(dp[i][j]!=0){
		return dp[i][j];
	}

	long long int op1=a[i]+min(MaxPointsToWin(a,i+1,j-1),MaxPointsToWin(a,i+2,j));
	long long int op2=a[j]+min(MaxPointsToWin(a,i+1,j-1),MaxPointsToWin(a,i,j-2));
	return dp[i][j]=max(op1,op2);
}

int main() {
	long long int n;
	cin>>n;

	long long int a[n];
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<MaxPointsToWin(a,0,n-1);
	return 0;
}