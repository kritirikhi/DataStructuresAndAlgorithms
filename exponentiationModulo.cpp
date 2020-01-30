#include<iostream>
using namespace std;

int main() {
    long long int a,b,c;
    cin>>a>>b>>c;

    a=a%c;
    long long int exponent=1;
    while(b>0){
        long long int lastbit=b&1;
        if(lastbit==1){
            exponent=(exponent*a)%c;
        }
        a=(a*a)%c;
        b=b>>1;
    }
    cout<<exponent%c;
	return 0;
}