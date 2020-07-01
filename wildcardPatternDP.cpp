//                                                                   WILDCARD PATTERN
// Given a text 'str' and a wildcard pattern 'pattern', The wildcard pattern can include the characters ‘?’ and ‘ * ’.
// ‘?’ – matches any single character
// ‘*’ – Matches any sequence of characters (including the empty sequence)
// Find out if the given text matches the pattern.

// Input Format
// Every test file will consist of two strings. First string represents 'str'. Second string represents 'pattern'.

// Constraints
// Size(str)*Size(pattern) < 100000000

// Output Format
// Print 1 if the string matches the pattern, else print 0.

// Sample Input
// aa a*a
// Sample Output
// 1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool match(string text,string pattern){
    int r = text.length();
    int c = pattern.length();
    
    bool dp[r+1][c+1];
    memset(dp, false, sizeof(dp));
    
    dp[0][0]=true;
    
    for(int i=1;i<=c;i++){
        if(pattern[i-1]=='*'){
            dp[0][i]=dp[0][i-1];
        }
    }
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(pattern[j-1]==text[i-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            
            else if(pattern[j-1]=='*'){
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
            
            else if(pattern[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            
            else{
                dp[i][j]=false;
            }
        }
    }
    
    return dp[r][c];
}

int main() {
    string s,pattern;
    cin>>s>>pattern;
    
    if(match(s,pattern)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
	return 0;
}
