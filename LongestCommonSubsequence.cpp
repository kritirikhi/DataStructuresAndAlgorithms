//                                                          LONGEST COMMON SUBSEQUENCE
// given two strings we have to find the length of the longest common subsequence 

// Approach
// i,j are thee indexes of 1st and the 2nd string respectively
// if the first characters of the two strings match then we can call on the remaining subproblem func(a,b,i+1,j+1)
// if characters not match then we havetwo options
//      either include ith character and exclude jth character
//      either exclude ith character and include jth character

// recursively solve the problem and till traverse the whole string

#include <iostream>
using namespace std;

//TOP DOWN
int longestCommonSubseq(string a,string b,int i,int j,int dp[][1000]){
    if(i==a.length() || j==b.length()){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int ans;
    if(a[i]==b[j]){
        ans=1+longestCommonSubseq(a,b,i+1,j+1,dp);
    }
    
    else{
        ans=max(longestCommonSubseq(a,b,i+1,j,dp) , longestCommonSubseq(a,b,i,j+1,dp));
    }
    
    return dp[i][j]=ans;
}

//BOTTOM UP 

// if ith char of a and jth char of b mathces then dp[i][j] = dp[i-1][j-1] + 1
// if not match then
//      dp[i][j] = max(dp[i-1][j],dp[i][j-1])
int longestCommonSubseqBU(string a,string b){
    int m=a.length();
    int n=b.length();
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i-1]==a[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    
    string a,b;
    cin>>a>>b;
    
    int dp[1000][1000];
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            dp[i][j]=-1;
        }
    }
    
    cout<<longestCommonSubseqBU(a,b);
	return 0;
}
