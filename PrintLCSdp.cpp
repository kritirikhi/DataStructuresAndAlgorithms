//                                                                  PRINT THE LONGEST COMMON SUBSEQUENCE
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach
// Make the dp 2D array as formed to calc the len of the LCS
// start traversing from the lowest right corner

//     if a[r-1]==b[c-1] then push that char in the resultant string and move diagonally
//     else if dp[r-1][c]>dp[r][c-1] then move in the direction of greater val i.e r--
//     else c--

string LCS(string a,string b){
    int r=a.length();
    int c=b.length();
    
    int dp[r+1][c+1];
    
    for(int i=0;i<=r;i++){
        dp[i][0]=0;
    }
    
    for(int i=0;i<=c;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(b[j-1]==a[i-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    int row=r;
    int col=c;
    string result;
    while(row>=0 && col>=0){
        if(a[row-1]==b[col-1]){
            result.push_back(b[col-1]);
            row--;
            col--;
        }
        else if(dp[row-1][col] > dp[row][col-1]){
			row--;
		}
		else{
			col--;
		}
    }
    
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    string a,b;
    cin>>a>>b;
    
    string LongestCommonSubseq=LCS(a,b);
    cout<<LongestCommonSubseq;
	return 0;
}