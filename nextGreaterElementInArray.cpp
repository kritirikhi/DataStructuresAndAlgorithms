// finding the next greater element in the array
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    stack <int> s;

    s.push(a[0]);

    for(int i=1;i<n;i++){
        if(a[i]>s.top() && !s.empty()){
            while(!s.empty() && s.top()<a[i]){
                cout<<a[i]<<" ";
                s.pop();
            }
            s.push(a[i]);
        }
        else{
            s.push(a[i]);
        }

    }

    while(!s.empty()){
        cout<<"-1"<<" ";
        s.pop();
    }
}
