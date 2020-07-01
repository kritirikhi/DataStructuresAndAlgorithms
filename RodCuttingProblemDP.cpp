//                                              ROD CUTTING TO MAX PROFIT 
// there is a rod of len N. We have to cut the rod into pieces for selling. The profit for pieces of len 1 to N are given.
// find the max profit we can make by selling the rod pieces


// Approach

// TOP DOWN 
// for the rod of len N (totalLength) we will find the max profit we can make from the rod of len n-1 till rod of len 0
// from the rod of len 0 the profit will be 0 (BASE CASE)
// As the overlapping subproblems occur so we can reduce that by DP array which will store the states i.e the ith index will give the max profit one can make from rod of len i
// O(n*n)


// BOTTOM UP
// dp[0]=0;
// for len=1 to totalLength
//      iterate from cut=1 to len
//          find the max possible profit for the len 
//          maximum = max(maximum , a[cut]+dp[len-cut])
//      the max possible profit for the len l is stored in dp
//

#include <iostream>
using namespace std;

// TOP DOWN
int maxProfit(int a[],int totalLength,int dp[]){
    if(totalLength==0){
        return 0;
    }
    
    if(dp[totalLength]!=-1){
        return dp[totalLength];        
    }
    
    int maximum=0;
    for(int i=1;i<=totalLength;i++){
        int profit=a[i] + maxProfit(a,totalLength-i,dp);
        maximum=max(maximum,profit);
    }
    
    return dp[totalLength]=maximum;
}


// BOTTOM UP 
int maxProfitBU(int a[],int totalLength){
    int dp[100]={0};
    
    for(int currLen=1;currLen<=totalLength;currLen++){
        int maximum=0;
        for(int cut=1;cut<=currLen;cut++){
            maximum=max(maximum,a[cut]+dp[currLen-cut]);
        }
        dp[currLen]=maximum;
    }
    
    return dp[totalLength];
}

int main() {
	int totalLength;
	cin>>totalLength;
	
	int dp[1000];
	//dp[0]=-1;
	
	int a[1000];
	for(int i=1;i<=totalLength;i++){
	    //dp[i]=-1;
	    cin>>a[i];
	}
	
// 	int ans=maxProfit(a,totalLength,dp);
// 	cout<<ans;

    int ans=maxProfitBU(a,totalLength);
	cout<<ans;
	return 0;
}
