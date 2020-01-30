#include <iostream>
using namespace std;

// method 1 for counting set bits
int countBits1(int n){
    int count=0;
    while(n>0){
        count+=n&1;
        n=n>>1;
    }
    return count;
}

// method 2 for counting set bits( more efficient method )  complexity of order O( no of set bits )
int countBits2(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    // method 1
    cout<<countBits1(n)<<endl;

    // method 2
    cout<<countBits2(n)<<endl;

    //method 3
    cout<<__builtin_popcount(n);
}
