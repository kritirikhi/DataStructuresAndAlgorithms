// Given n friends, each one can remain single or can be paired up with some other friend.
// Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

// Examples :
// Input  : n = 3
// Output : 4

// Explanation
// {1}, {2}, {3} : all single
// {1}, {2, 3} : 2 and 3 paired but 1 is single.
// {1, 2}, {3} : 1 and 2 are paired but 3 is single.
// {1, 3}, {2} : 1 and 3 are paired but 2 is single.
// Note that {1, 2} and {2, 1} are considered same.

//Approach
// for nth friend there are 2 options  f(n)
//      to go alone f(n-1)
//      to make a pair with any from n-1 friends (n-1)*f(n-2)

#include <iostream>
using namespace std;

//TOP DOWN
int friendsPairingTopDown(int n,int dp[]){
    if(n==0 || n==1 || n==2){
        dp[n]=n;
        return n;
    }
    
    // Memoisation
    if(dp[n]!=-1){
        return dp[n];
    }
  
    int ans=friendsPairingTopDown(n-1,dp)+(n-1)*friendsPairingTopDown(n-2,dp);
    
    return dp[n]=ans;
}

//BOTTOM UP
// int friendsPairing(int n){
//     int dp[n+1];
//     dp[0]=0;
//     dp[1]=1;
//     dp[2]=2;
    
//     for(int i=3;i<=n;i++){
//         dp[i] = dp[i-1] + (i-1)*dp[i-2];
//     }
    
//     return dp[n];
// }

int main() {
    
    int n;
    cin>>n;
    
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    
    cout<<friendsPairingTopDown(n,dp);
	return 0;
}
