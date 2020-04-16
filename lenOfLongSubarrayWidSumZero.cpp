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
    
    unordered_map <int,int> m;
    int pref=0;
    int len=INT_MIN;
    
    for(int i=0;i<n;i++){
        pref+=a[i];
        if(a[i]==0  && len==0){
            len++;
        }
        if(pref==0){
            len=max(len,i+1);
        }
        if(m.find(pref)!=m.end()){
            len=max(len,i-m[pref]);
        }
        else{
            m[pref]=i;   
        }
    }
    cout<<len;
	return 0;
}
