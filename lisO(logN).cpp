//                                                           LONGEST INCREASING SUBSEQUENCE BETTER APPROACH
//============================================================================================================================================================================
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// function which discusses the APPROACH 

// in this APPROACH
//     dp[i] will store the element at which the LIS of length i ends 
//     As there can be many elements at which the LIS of length i ends so we will take the min element into consideration
//     min element is taken into consideration because there can be chance of making more increasing subsequence with that min element
    
//     the dp array will be of len n+1 
//     initially dp[0]=INT_MIN and rest dp array will be initialised to INT_MAX
    
//     now for each element in the given array we will find the dp position such that:- 
//         dp[position] < array element < dp[position+1]
        
//     if we are able to find the position dp[position+1] = array element 
//     these steps will take place for all array elements one by one
    

int lis(int a[],int n){
    int dp[n+1];
    dp[0]=INT_MIN;
    
    for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(dp[j]<a[i] && a[i]<dp[j+1]){
                dp[j+1]=a[i];
                break;
            }
        }
    }
    
    int len=0;
    for(int i=0;i<=n;i++){
        if(dp[i]!=INT_MAX){
            len=i;
        }
    }
    
    return len;
}

// From the above approach the condition was 
//     if dp[position] < array element < ap[position+1] 
//     then dp[position+1] = array element
    
//     hence that means for every array element we have to find the first greater element in dp array 
//     that first greater element is present at position p 
//     then the dp[p] = array element 
//     the first greater element will be found by using binary search or UPPER_BOUND function of STL
//     we will repeat the procedure for all array elements
    
// for N elements we are searching the position in dp array in logN time hence the time complexity of the entire algorithm becomes O(NlogN)


// using binary search UPPER BOUND
int lisUpperBound(int a[],int n){
    int dp[n+1];
    dp[0]=INT_MIN;
    
    for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
    }
    
    for(int i=0;i<n;i++){
        int length = upper_bound(dp,dp+n+1,a[i]) - dp;
        if(dp[length-1]<a[i] && a[i]<dp[length]){
            dp[length] = a[i];
        }
    }
    
    int len=0;
    for(int i=0;i<=n;i++){
        if(dp[i]!=INT_MAX){
            len=i;
        }
    }
    
    return len;
}

int main() {
	int a[5]={5,4,3,2,1};
	int n=5;
	
	int len = lisUpperBound(a,n);
	cout<<len;
	return 0;
}
