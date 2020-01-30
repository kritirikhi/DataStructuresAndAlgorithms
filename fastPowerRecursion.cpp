#include <iostream>
using namespace std;

long long int calcPower(long long int num,long long int pow){
    if(pow==0){
        return 1;
    }
    long long int ans=num*calcPower(num,pow-1);
    return ans;
}

long long int fastPower(long long int num,long long int pow){
    if(pow==0){
        return 1;
    }
    int smallAns=fastPower(num,pow/2);
    smallAns=smallAns*smallAns;
    if(pow&1){
        return num*smallAns;
    }
    return smallAns;
}

int main() {
    long long int num,pow;
    cin>>num>>pow;

    //cout<<calcPower(num,pow);
    cout<<fastPower(num,pow);
}
