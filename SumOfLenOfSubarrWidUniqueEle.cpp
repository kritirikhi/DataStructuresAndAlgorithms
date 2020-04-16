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

    unordered_map<int,bool> mp;
    int j=0;
    int ans=0;
    for(int i=0;i<n;i++){

        while(j<n && mp[a[j]]==false ){
            mp[a[j]]=true;
            j++;
        }

        ans=ans+((j-1-i+1)*(j-1-i+2))/2;
        mp.erase(a[i]);
    }
    cout<<ans;
}
