// Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)
// (Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)
// Since the answer may be large, return the answer modulo 10^9 + 7.
// Example :
// Input: n = 5
// Output: 12
// Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
// Constraints:
// 1 <= n <= 100


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define MOD 1000000007

long long int factorial(int n){
    long long res=1;
    for(int i=2;i<=n;i++){
        res=(res*i)%MOD;
    }
    return res%MOD;
}


long long int numPrimeArrangements(int n)
{
    // prime sieve
    int primes[1000]={0};
    for(int i=3;i<=n;i+=2){
        primes[i]=1;
    }
    
    for(int i=3;i<=n;i+=2){
        for(int j=i*i;j<=n;j+=2*i){
            primes[j]=0;
        }
    }
    
    primes[2]=1;
    primes[0]=primes[1]=0;
    
    
    int primeNums=0;
    for(int i=2;i<=n;i++){
        if(primes[i]){
            primeNums++;
        }
    }
    
    long long int NoOfPermuations=(factorial(n-primeNums)*factorial(primeNums))%MOD;
    return NoOfPermuations;

}

int main() {
    int n;
    cin>>n;

    cout<<numPrimeArrangements(n);    
}
