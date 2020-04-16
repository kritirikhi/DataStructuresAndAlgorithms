#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    unordered_set<int> s;
    int pref=0;
    int flag=0;

    for(int i=0;i<n;i++){
        pref+=a[i];
        if(pref==0 || s.find(pref)!=s.end()){
            flag=1;
            break;
        }
        s.insert(pref);
    }

    if(flag==1){
        cout<<"subarray wid zero sum is present";
    }
    else{
        cout<<"subarray wid zero sum is not present";
    }
}
