//                                                                      MIXTURES PROBLEM 
// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together,
// and put the resulting mixture in their place.

// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

// Input:
// 2
// 18 19
// 3
// 40 60 20

// Output:
// 342
// 2400
// In the second test case, there are two possibilities:

// first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400
// first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400
// The first scenario is a much better way to proceed.


#include <iostream>
#include<climits>
using namespace std;

long long int sum(long long int a[],long long int s,long long int e){
    long long int sum1=0;
    for(long long int i=s;i<=e;i++){
        sum1=sum1+a[i];
        sum1=sum1%100;
    }
    return sum1;
}

long long int solveMixtures(long long int a[],long long int i,long long int j,long long int dp[][1000]){
    if(i>=j){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    dp[i][j]=INT_MAX;
    for(long long int k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],solveMixtures(a,i,k,dp)+solveMixtures(a,k+1,j,dp)+sum(a,i,k)*sum(a,k+1,j));
    }
    
    return dp[i][j];
}

int main() {
    long long int n;
    
    while((scanf("%d",&n))!=EOF){
        long long int dp[1000][1000];
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
    
        long long int a[n];
        for(long long int i=0;i<n;i++){
            cin>>a[i];
        }
    
        cout<<solveMixtures(a,0,n-1,dp)<<endl;
    }
	return 0;
}