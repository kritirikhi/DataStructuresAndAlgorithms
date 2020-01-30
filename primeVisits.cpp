#include<iostream>
using namespace std;


int main() {
    long long int n=90000000;
    long long int primes[n]={0};
    
    // marking odd numbers as prime
    for(long long int i=3;i<=n;i+=2){
        primes[i]=1;
    }
    // taking odd numbers and marking their multiples as not prime
    for(long long int i=3;i<=n;i+=2){
	    for(long long int j=i*i;j<=n;j=j+2*i){
            primes[j]=0;
	    }
    }
    // case when n=2,1,0
    primes[0]=primes[1]=0;
    primes[2]=1;
   
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
        int a,b;
        cin>>a>>b;
        int count=0;
        for(int i=a;i<=b;i++){
            if(primes[i]){
                count++;
            }
        }
        cout<<count<<endl;
    }
	return 0;
}