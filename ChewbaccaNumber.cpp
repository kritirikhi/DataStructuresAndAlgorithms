#include <iostream>
#include<cstring>
using namespace std;
int main() {
    string a;
    cin>>a;

    int digit;
    long long int i=0;
    if(a[0]=='9'){
        i++;
    }
    for(;a[i]!='\0';i++){
        int digit;
        digit=a[i]-'0';
        if(digit>=5){
            digit=9-digit;
            a[i]=digit+'0';
        }
    }
    cout<<a;
}
