#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long int t;
    cin>>t;
    
    for(long long int x=0;x<t;x++){
        long long int n,d;
        cin>>n>>d;
        
        long long int a[n];
        for(long long int i=0;i<n;i++){
            cin>>a[i];
        }
        
        for(long long int i=n-1;i>=0;i--){
            if(d%a[i]==0){
                continue;
            }
            
            else{
                long long int r=d%a[i];
                d=d-r;
            }
        }
        
        cout<<"Case #"<<x+1<<": "<<d<<endl;
    }
	return 0;
}
