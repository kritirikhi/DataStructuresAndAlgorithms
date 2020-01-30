#include <iostream>
using namespace std;
long long int primes[90000000];
long long int a[1000000];
int main() {

    //  The Prime sieve 
    for(long long int i=3;i<=90000000;i+=2){
        primes[i]=1;
    }
    for(long long int i=3;i<=90000000;i+=2){
        for(long long int j=i*i;j<=90000000;j+=2*i){
            primes[j]=0;
        }
    }
    primes[0]=primes[1]=0;
    primes[2]=1;

    // array of prime numbers
    int k=0;
    for(int i=0;i<=90000000;i++){
        if(primes[i]){
            a[k]=i;
            k++;
        }
    }

    // testcases

    long long int t;
    cin>>t;

    for(long long int x=0;x<t;x++){
        long long int no;
        cin>>no;

        cout<<a[no-1]<<endl;
    }
    return 0;
}
