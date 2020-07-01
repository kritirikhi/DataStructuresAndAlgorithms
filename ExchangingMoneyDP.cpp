//                                                                          Exchanging Coins

// Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. 
// A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. 
// You have one copper coin. What is the maximum weight of gold one can get from it?

// Input Format
// The input file contains a single integer n, the number on the coin.

// Constraints
// 0 <= n <= 1 000 000 000

// Output Format
// Print the maximum weight of gold you can get.

// Sample Input
// 12
// Sample Output
// 13


// Bottom up DP cant be used as for n>10^7 DP array cant be created
// so we will create DP array of size 10^7 and if n>10^7 then we will call recursively for that value of N

#include <iostream>
using namespace std;

long long int dp[10000000]={0};

long long calcMaxGoldWeight(long long int n){
    if(n<=11){
        return n;
    }
    
    if(n<10000000){
        if(dp[n]!=0){
            return dp[n];
        }
        else{
            long long int op=calcMaxGoldWeight(n/2)+calcMaxGoldWeight(n/3)+calcMaxGoldWeight(n/4);
            dp[n]=max(n,op);
            return dp[n];
        }
    }
    
    long long int op=calcMaxGoldWeight(n/2)+calcMaxGoldWeight(n/3)+calcMaxGoldWeight(n/4);
    return max(n,op);
}

int main() {
	long long int n;
	cin>>n;
	
	cout<<calcMaxGoldWeight(n);
	return 0;
}
