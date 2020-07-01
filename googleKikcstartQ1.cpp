#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    
    for(int x=0;x<t;x++){
        int n;
        cin>>n;
        
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        int peaks=0;
        for(int i=1;i<=n-2;i++){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                peaks++;
            }
        }
        
        cout<<"Case #"<<x+1<<": "<<peaks<<endl;
    }
	return 0;
}
