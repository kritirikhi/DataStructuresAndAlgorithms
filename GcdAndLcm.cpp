#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main() {
    int n1,n2;
    cin>>n1>>n2;
    int hcf=gcd(n1,n2);
    cout<<"gcd of "<<n1<<" , "<<n2<<" is "<<hcf<<endl;
    int lcm=(n1*n2)/hcf;
    cout<<"lcm of "<<n1<<" , "<<n2<<" is "<<lcm;
}
