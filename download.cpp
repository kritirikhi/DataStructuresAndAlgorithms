#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int numPrimeArrangements(int n)
{
    // prime sieve
    int primes[1000]={0};
    for(int i=3;i<=n;i+=2){
        primes[i]=1;
    }
    
    for(int i=3;i<=n;i+=2){
        for(int j=i*i;j<=n;j=2*i){
            primes[j]=0;
        }
    }
    
    primes[2]=1;
    primes[0]=primes[1]=0;
    

    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    int count=0;
    do { 
        int flag=0;
        for(int i=0;i<n;i++){
            if(primes[a[i]]==1 && primes[i+1]!=1){
                flag=1;
                break;
            }
            
        }
        if(!flag){
            count++;
        }
    } while (next_permutation(a, a + n)); 
    
    return count;

}
