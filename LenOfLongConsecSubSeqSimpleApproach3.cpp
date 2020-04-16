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
    
    set <int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s.find(a[i]-1)!=s.end()){
            continue;
        }
        else{
            int x=a[i];
            int count=0;
            while(s.find(x)!=s.end()){
                count++;
                x++;
            }
            ans=max(ans,count);
        }
    }
    cout<<ans;
	return 0;
}
