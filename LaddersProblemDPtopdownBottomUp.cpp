//                                                              LADDERS PROBLEM  
// there are n steps and a boy is on the ground floor. He has to reach at the top (nth step) 
// calculate the no of ways to reach the nth step and the boy can take at max k steps from the ith step

#include <iostream>
using namespace std;

// TOP DOWN
int calcWays(int n,int k,int dp[]){
    if(n==0){
        return 1;
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ways=0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            ways=ways+calcWays(n-i,k,dp);   
        }
    }
    
    return dp[n]=ways;
}

// BOTTOM UP 

int calcWaysBU(int n,int k){
    int dp[100]={0};
    
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j<0){
                break;
            }
            dp[i]+=dp[i-j];
            
        }        
    }
    
    return dp[n];
}

int main() {
    
    int n,k;
    cin>>n>>k;
    
    //int dp[100]={0};
    //cout<<calcWays(n,k,dp);
    
    cout<<calcWaysBU(n,k);
	return 0;
}
