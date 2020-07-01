//                                                                      Prime Factorization Of a Number 


// Given a number n, We have to find the prime factorization of the number 

// 3 approaches
//      brute force(NAIVE)
//      optimiesd version of brute force 
//      using prime sieve 

#include <iostream>
#include <vector>
using namespace std;


// brute force O(N)
// run a loop from 2 upto n and  find whether the no divides the n and reduce n accordingly
void primefactor(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                cout<<i<<" ";
                n=n/i;
            }
        }
    }
}

// OPTIMISED O(sqrt(N))
// similar to brute force but the loop is run till sqrt(n)
// every no has atleast one prime factor less than sqrt of that number 
void primefactorOptimised(int n){
    vector<pair<int,int>> primefactors;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                count++;
                n=n/i;
            }
            
            primefactors.push_back(make_pair(i,count));
        }
    }
    
    if(n!=1){
        primefactors.push_back(make_pair(n,1));
    }
    
    for(auto x:primefactors){
        cout<<x.first<<"^"<<x.second<<endl;
    }
}


// construction of prime sieve
vector<int> primeSieve(int n){
    vector<int> prime;
    
    int a[n+1]={0};
    
    for(int i=3;i<n+1;i=i+2){
        a[i]=1;
    }
    
    for(int i=3;i<n+1;i=i+2){
        for(int j=i*i;j<n+1;j+=2*i){
            a[j]=0;            
        }
    }
    
    a[2]=1;
    
    for(int i=2;i<n+1;i++){
        if(a[i]==1){
            prime.push_back(i);
        }
    }
    return prime;
}

// finding the prime factors using prime sieve O(logN)
void factorize(int n,vector<int> &primeNum){
    int p=primeNum[0];
    int i=0;
    
    vector<int> factors;
    
    // ITERATE OVER ALL THE PRIME FACTORS WHICH ARE LESS THAN SQRT OF THE NUMBER 
    while(p*p<=n){
        if(n%p==0){
            factors.push_back(p);
            while(n%p==0){
                n=n/p;
            }
        }
        i++;
        p=primeNum[i];
    }
    
    for(auto x:factors){
        cout<<x<<" ";
    }
}

int main() {
    // int n;
    // cin>>n;
    
  //  primefactor(n);
  //  primefactorOptimised(n);
  
    vector<int> primeNum=primeSieve(1000);
    
    int n;
    cin>>n;
    
    factorize(n,primeNum);
	return 0;
}
