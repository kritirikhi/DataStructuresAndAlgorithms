//                                                          K kOrderedLCS

// Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

// In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

// Input Format
// The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively. The second line contains N integers denoting the elements of the first sequence. The third line contains M integers denoting the elements of the second sequence.

// Constraints
// 1 <= N, M <= 2000 1 <= k <= 5 1 <= element in any sequence <= 109

// Output Format
// Print the answer in a new line.

// Sample Input
// 5 5 1
// 1 2 3 4 5
// 5 3 1 4 2
// Sample Output
// 3

#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 

long long int kOrderedLCS(long long int dp[2001][2001][52],long long  int arr1[], long long int n,long long int arr2[], long long int m, long long int k) { 
    if (k < 0) 
        return INT_MIN; 
  
    if (n < 0 || m < 0) 
        return 0; 
  
    long long int ans = dp[n][m][k]; 
  
   
    if (ans != -1) 
        return ans; 
  
    ans = max(kOrderedLCS(dp, arr1, n - 1, arr2, m, k),kOrderedLCS(dp, arr1, n, arr2, m - 1, k)); 
   
    if (arr1[n-1] == arr2[m-1]) 
        ans = max(ans, 1 + kOrderedLCS(dp, arr1, n - 1,arr2, m - 1, k)); 
                                
    ans = max(ans, 1 + kOrderedLCS(dp, arr1, n - 1, arr2, m - 1, k - 1)); 
  
    dp[n][m][k]=ans;
    return dp[n][m][k]; 
} 
  
int main() 
{ 
    long long int n,m,k;
    cin>>n>>m>>k;
    
    long long int arr1[n];
    long long int arr2[m];
    
    for(long long int i=0;i<n;i++){
        cin>>arr1[i];
    }
    
    for(long long int i=0;i<m;i++){
        cin>>arr2[i];
    }
 
    long long int dp[2001][2001][52]; 
    memset(dp, -1, sizeof(dp)); 
  
    cout << kOrderedLCS(dp, arr1, n, arr2, m, k); 
  
    return 0; 
} 