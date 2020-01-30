#include <iostream>
using namespace std;
int decToBinary(int n){
    int ans=0;
    int p=1;
    while(n>0){
        int lastbit=n&1;
        ans=ans+(lastbit*p);
        p=p*10;
        n=n>>1;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;

    cout<<decToBinary(n);
}
