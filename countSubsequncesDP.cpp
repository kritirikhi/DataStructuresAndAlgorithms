//                                                                          COUNT SUBSEQUENCES
// Given a string, count the number of distinct subsequences of it ( including empty subsequence ). 
// For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without 
// disturbing the relative positions of the remaining characters. For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

// Input Format
// First line of input contains an integer 't' denoting number of test cases.
// Next t lines contain a string each.

// Constraints
// 1<=t<=100
// 1<=length of s<=100000
// s will contain upper letters only.

// Output Format
// For each test case ,print ans%1000000007 in a new line each ,where ans is the number of distinct subsequences.

// Sample Input
// 2
// AAA
// ABCDEFG
// Sample Output
// 4
// 128
// Explanation
// For "AAA" , the distinct subsequences that can be formed are { '', 'A' , 'AA' , 'AAA }. So we print 4 , no of distinct subsequences.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int countSubseq(string s){
    long long int n=s.length();
    long long int dp[n+1]={0};
    dp[0]=1;
    
    vector<long long int> visited(256, -1); 
    
    for(long long int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        dp[i]=dp[i]%1000000007;
        
        if(visited[s[i-1]]!=-1){
            dp[i]=dp[i]-dp[visited[s[i-1]]];
            dp[i]=dp[i]%1000000007;
        }
        
        visited[s[i-1]]=(i-1);
    }
    
    return dp[n];
}

int main() {
    long long int t;
    cin>>t;
    
    for(long long int x=0;x<t;x++){
        string s;
        cin>>s;
        cout<<countSubseq(s)<<endl;
    }
	return 0;
}
