//                  MIN STEPS TO ONE (BOTTOM UP)
// for every num i dp[i]=min( dp[i-1],min(dp[i/2],dp[i/3]) )
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin>>n;
    
    int dp[n+1]={0};
    dp[1]=0;
    
    for(int i=2;i<=n;i++){
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        
        if(i%2==0){
            op1=dp[i/2];
        }
        if(i%3==0){
            op2=dp[i/3];
        }
        
        op3=dp[i-1];
        
        dp[i]=min(min(op1,op2),op3)+1;
    }
   
    cout<<dp[n];
	return 0;
}
