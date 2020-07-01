#include <iostream>
using namespace std;

int maxValueKnapsack(int w[],int v[],int n,int W){
    int dp[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    
    for(int i=0;i<=W;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    
    
    return dp[n][W];
}

int main() {
    int n,W;
    cin>>n>>W;
    
    int w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    cout<<maxValueKnapsack(w,v,n,W);
	return 0;
}
