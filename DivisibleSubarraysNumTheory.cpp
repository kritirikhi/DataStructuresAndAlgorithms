#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin>>n;

    long long int a[n];
    long long int freqRem[n]={0};
    freqRem[0]=1;   // for the null subarray
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
        sum=sum%n;
        sum=(sum+n)%n;
        freqRem[sum]++;
    }
    long long int ans=0;
    for(long long int i=0;i<n;i++){
        long long int no= (freqRem[i]*(freqRem[i]-1))/2;
        ans=ans+no;
    }
    cout<<ans;

}
