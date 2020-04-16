#include <iostream>
using namespace std;

int fibonacciTopDown(int n,int dp[]){
    if(n==1 || n==0){
        return n;
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ans;
    ans=fibonacciTopDown(n-1,dp)+fibonacciTopDown(n-2,dp);
    dp[n]=ans;
    return ans;
}

int main() {
    int n;
    cin>>n;
    
    int dp[100]={0};
    cout<<fibonacciTopDown(n,dp);
    
	return 0;
}
