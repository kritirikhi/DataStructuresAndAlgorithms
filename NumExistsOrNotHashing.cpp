#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[n];
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    int output[2*n];
    int size=0;
    int idx=0;
    for(int j=0;j<n;j++){
        if(mp[b[j]]>0){
            output[idx]=b[j];
            mp[b[j]]--;
            idx++;
            size++;

        }
    }

    sort(output,output+size);
    cout<<"[";
    for(int i=0;i<size-1;i++){
        cout<<output[i]<<", ";
    }
    cout<<output[size-1]<<"]";
}
