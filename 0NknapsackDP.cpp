#include <iostream>
using namespace std;

long long int maxValueKnapsack(long long int w[],long long int v[],long long int n,long long int W){
    long long int dp[W+1]={0};
    
    for(long long int i=1;i<=W;i++){
        for(long long int j=0;j<n;j++){
            if(w[j]<=i){
                dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
            }
        }
    }
    
    return dp[W];
    
}

int main() {
    long long int n,W;
    cin>>n>>W;
    
    long long int w[n];
    for(long long int i=0;i<n;i++){
        cin>>w[i];
    }
    
    long long int v[n];
    for(long long int i=0;i<n;i++){
        cin>>v[i];
    }
    
    cout<<maxValueKnapsack(w,v,n,W);
	return 0;
}
