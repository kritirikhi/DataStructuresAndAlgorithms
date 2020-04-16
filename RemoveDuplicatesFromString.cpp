#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char a[n+1];
    cin>>a;

    if(strlen(a)==1 || strlen(a)==0){
        cout<<a;
    }
    else{
        int prev=0;
        int curr=1;
        while(a[curr]!='\0'){
            if(a[prev]!=a[curr]){
                prev++;
                a[prev]=a[curr];
            }
            curr++;
        }
        a[prev+1]='\0';
        cout<<a;
    }
}
