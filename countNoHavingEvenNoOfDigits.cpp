// to count the numbers in an array which have even no of digits
#include <iostream>
using namespace std;
int main() {
    // input n (no of elements) and the array of n elements 
    long long int n;
    cin>>n;

    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }

    // the even no of digits lie between the following range of numbers
    // 10-99
    // 1000-9999
    // 1000000-999999
    long long int count=0;
    for(long long int i=0;i<n;i++){
        if( (a[i]>=10 && a[i]<=99) || (a[i]>=1000 && a[i]<=9999) || (a[i]>=100000 && a[i]<=999999) ){
            count++;
        }   
    }
    cout<<count;
}
