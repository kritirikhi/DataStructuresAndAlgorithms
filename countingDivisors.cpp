//                                                              COUNTING THE TOTAL NUMBER OF DIVISORS OF A NUMBER
// Eg:- 
//     for number 60 the output is 12 (1,2,3,4,5,6,10,12,15,20,30,60)
    
// Approach
//     do the prime factorization of the number 
//     for 60 its is 2^2 3^1 5^1 
//     the no of divisors possible for 60 are (2+1 * 1+1 * 1+1) = 12 
    
//     for f1^p1 f2^p2 f3^p3 -------
//     the no of divisors possible for the number will be (p1+1)*(p2+1)*(p3+1)-----------  

#include <iostream>
#include <vector>
using namespace std;

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
int countDivisors(int n,vector<int> &primeNum){
    int p=primeNum[0];
    int i=0;
    int ans=1;
    // ITERATE OVER ALL THE PRIME FACTORS WHICH ARE LESS THAN SQRT OF THE NUMBER 
    while(p*p<=n){
        if(n%p==0){
            int count=0;
            while(n%p==0){
                n=n/p;
                count++;
            }
            ans=ans * (count+1);
        }
        i++;
        p=primeNum[i];
    }
    if(n!=1){
        ans=ans*2;
    }
    return ans;
}

int main() {
    vector<int> primeNum=primeSieve(1000);
    int n;
    cin>>n;
    cout<<countDivisors(n,primeNum);
	return 0;
}
