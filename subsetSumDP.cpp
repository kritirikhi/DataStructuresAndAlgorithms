//                                                                          Subset Sum Problem

// for ith index in the array if a[i]>target sum then we cant include that element hence we will take the value calculated before 
// if a[i]<target then we have to options 
        // option1 = include the element and we will take the value of n-1 elements giving the target as target-a[i]
        // option2 = exclude the element and we will take the value of n-1 elements calculated before 
        
        
// make a 2d boolean DP array [n+1][target+1]

//BASE CASES
// when target=0
// then dp[i][0]=true  for i=0 to n

// when array is empty and target is non zero
// dp[0][i]=false  for i=0 to target


// iterate row wise in dp array and fill the columns  
// if(a[i-1]>j)   dp[i][j]=dp[i-1][j]                 (i is row index and j is col index)
// else dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]]

#include <iostream>
using namespace std;

bool subsetSum(int a[],int n,int target){
    bool dp[n+1][target+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=0;i<=target;i++){
        dp[0][i]=false;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(a[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
    }
    
    return dp[n][target];
    
}

int main() {
    
    int n,target;
    cin>>n>>target;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    if(subsetSum(a,n,target)){
        cout<<"Yes";
    }
    
    else{
        cout<<"No";
    }
    
	return 0;
}
