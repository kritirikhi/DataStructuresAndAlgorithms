#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin>>n;

    long long int primes[n]={0};
    
    // making odd places as prime
    for(long long int i=3;i<=n;i+=2){
        primes[i]=1;
    }
    // traversing for each odd number and marking its multiples as not prime
    for(long long int i=3;i<=n;i+=2){
        for(long long int j=i*i;j<=n;j+=i){
            primes[j]=0;
        }
    }
    // special cases 
    primes[0]=primes[1]=0;
    primes[2]=1;
    // printing the sieve
    for(long long int i=0;i<=n;i++){
        if(primes[i]==1){
            cout<<i<<"  ";
        }
    }
}
