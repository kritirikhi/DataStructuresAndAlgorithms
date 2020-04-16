#include <iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
//    ====================================   prime sieve   ===============================================
    long long int n1=9000000;
    long long int primes[n1]={0};
    for(long long int i=3;i<=n1;i=i+2){
        primes[i]=1;
    }
    for(long long int i=3;i<=n1;i++){
        for(long long int j=i*i;j<=n1;j=j+2*i){
            primes[j]=0;
        }
    }
    primes[0]=primes[1]=0;
    primes[2]=1;

//==========================================================================================================
    stack<long long int> a,b,c;
    vector<long long int> v;
    long long int n,iterate;
    cin>>n>>iterate;

    long long int data;
    for(long long int i=0;i<n;i++){
        cin>>data;
        c.push(data);
    }

    
    for(long long int q=1;q<=iterate;q++){
        long long int primeNo;
        long long int count=0;
        for(long long int j=2;j<n1;j++){
            if(primes[j]==1){
                count++;
            }
            if(count==q){
                primeNo=j;
                break;
            }
        }
        while(!c.empty()){
            if(c.top()%primeNo==0){
                b.push(c.top());
                c.pop();
            }
            else{
                a.push(c.top());
                c.pop();
            }
        }
        swap(a,c);
        while(!b.empty()){
            v.push_back(b.top());
            b.pop();
        }
    }


    swap(a,c);
    for(long long int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    while(!a.empty()){
        cout<<a.top()<<endl;
        a.pop();
    }

}
