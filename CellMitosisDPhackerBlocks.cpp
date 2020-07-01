//                                                                           CELL MITOSIS

// there is one cell in laboratory. A scientist have to make n cells from the 1 cell and for that he can perform 3 operations
//          1) double the cells 
//          2) increment the cells by one
//          3) decrement the cells by one
// the three operations have x,y,z costs respectively
// find the min cost to make n cells

// if i is odd
// then we have 2 options either take dp[i-1]+y or dp[(i+1)/2]+x+z i.e reach i+1th index by doubling and reaching ith index by decrementing

// if i is even
// then we have 2 options either from dp[i/2]+x or dp[i-1]+y  we will take min of this

#include <iostream>
using namespace std;

int cellMitosis(int n,int x,int y,int z){
    int dp[n+1]={0};
    
    dp[0]=dp[1]=0;
    
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        }
        else{
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }
    }
    
    return dp[n];
}

int main() {
    
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    
    cout<<cellMitosis(n,x,y,z);
	return 0;
}
