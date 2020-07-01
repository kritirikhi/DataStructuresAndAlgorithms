//                                                              MINIMUM JUMPS REQUIRED
// You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps 
// required to reach at the end of the array.
// Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integers n which the size of array A[]. 
// Next line contains n space separated integers.

// Constraints
// 1<=t<=50
// 1<=n<=1000
// 0<=A[i]<=100

// Output Format
// Print the minimum number of jumps.

// Sample Input
// 1
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// Sample Output
// 3
// Explanation
// 1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9

//=========================================================================================================================================================================

// Approach
// make a dp array
// for ith index in dp array iterate over the input array from 0 to i-1  (j=0 to i-1)
// if the arr[j]+j >= i then we can find the dp[i]=min(dp[i],dp[j]+1)
// if no option is available then dp[i]=infinity i.e that position cant be reached


#include <iostream>
#include <climits>
using namespace std;


int minJumps(int a[],int n){
    int dp[n];
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(i<=j+a[j] && dp[j]!=INT_MAX){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    
    return dp[n-1];
}

int main() {
    int t;
    cin>>t;
    
    for(int x=0;x<t;x++){
	    int n;
	    cin>>n;
	
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cout<<minJumps(a,n)<<endl;
    }
	return 0;
}
