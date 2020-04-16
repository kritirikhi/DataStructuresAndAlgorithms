//                                                      MINIMUM COIN CHANGE BOTTOM APPROACH
// here we use the bottom up APPROACH
// dp[0]=0;
// for every i (0 to m) in coins array  dp[n]=dp[n-coins[i]]   (where n=1 to n(the actual amount)) provided n-coins[i]>=0


// for n=15 the dp array will be 
// dp indices   0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15 
// dp values    0  1  2  3  4  5  6  1  2  3   1   2   3   4   2   3   
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int minCoinChange(int n,int coins[],int m,int dp[]){
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
        
        dp[i]=INT_MAX;
        
        for(int j=0;j<m;j++){
            if(i-coins[j]>=0){
                int option=dp[i-coins[j]];
                dp[i]=min(dp[i],option+1);
            }
            else{
                break;
            }
        }
        
    }
    
    return dp[n];
}

int main() {
    int coins[]={1,7,10};
    int m=sizeof(coins)/sizeof(int);
    
    int n;
    cin>>n;

    int dp[1000]={0};
    cout<<minCoinChange(n,coins,m,dp);
	cout<<endl;
	for(int i=0;i<=n;i++){
	    cout<<dp[i]<<"  ";
	}
	
	return 0;
}
