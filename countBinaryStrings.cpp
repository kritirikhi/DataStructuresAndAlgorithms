//                                                                  COUNT THE BINARY STRINGS
// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

// Output Format
// Print the number of all possible binary strings.

// Sample Input
// 2
// 2
// 3
// Sample Output
// 3
// 5
// Explanation
// 1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101


#include <iostream>
using namespace std;

//APPROACH 1  BOTTOM UP DP
// we will make two arrays 
//     one will store the no of binary strings of len i ending with 0
//     other will store the no of binary strings of len i ending with 1 
    
// the base case will be 
//     no of binary strings of len 1 ending with zero = 1 i.e(0)
//     no of binary strings of len 1 ending with one = 1  i.e(1)
    
// the rest will be done in iteration
//     in the ith iteration
//         stringsendwith0[i]=stringsendwith0[i-1]+stringsendwith1[i-1] 
//         (the string ending with zero can be formed when 0 is appended at the end of stringsendwith0 + stringsendwith1)
//         stringsendwith1[i]=stringsendwith0[i-1] (the string ending with 1 can be formed when 1 is appended at the end of stringsendwith0)

int countBinaryString(int n){
    int lastDigitZero[n+1];
    int lastDigitOne[n+1];
    
    lastDigitOne[1]=lastDigitZero[1]=1;
    
    for(int i=2;i<=n;i++){
        lastDigitZero[i]=lastDigitZero[i-1]+lastDigitOne[i-1];
        lastDigitOne[i]=lastDigitZero[i-1];
    }
    return lastDigitZero[n]+lastDigitOne[n];
}


//APPROACH 2 
// when n=1 the count=2;
// whne n=2 the count=3;
// when n=3 the count=5;
// when n=4 the count=8;

// from the above, its clear that its fibonacci series
// so fibo(n)=fibo(n-1)+fibo(n-2)

// fibonacci
int dp[1000]={0};
int countBinaryStringFIBO(int n){
    if(n==0 || n==1){
        return n+1;
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ans;
    ans=countBinaryStringFIBO(n-1)+countBinaryStringFIBO(n-2);
    return dp[n]=ans;
}


int main() {
    int n;
    cin>>n;
    
    
    // fibonacci
    // dp[0]=1;
    // dp[1]=2;
    
    // cout<<countBinaryStringFIBO(n);
    
    // bottom up 
    cout<<countBinaryString(n);
	return 0;
}
