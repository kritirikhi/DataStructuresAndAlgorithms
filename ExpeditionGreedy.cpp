#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.first>p2.first;
}


int main() {
    long long int t;
    cin>>t;
    
    for(long long int tc=0;tc<t;tc++){
        long long int n;
        cin>>n;
        
        vector<pair<long long int,long long int>> v;
        for(long long int i=0;i<n;i++){
            long long int dist,fuel;
            cin>>dist>>fuel;
            
            v.push_back(make_pair(dist,fuel));
        }
        
        long long int D,F;
        cin>>D>>F;
        
        sort(v.begin(),v.end(),compare);
        for(long long int i=0;i<n;i++){
            v[i].first=D-v[i].first;
        }
        
        priority_queue<long long int> pq;
        long long int flag=0;
        long long int x=0;
        long long int prev=0;
        long long int ans=0;
        
        while(x<n){
            if(F>=v[x].first-prev){
                F = F - (v[x].first - prev);
                pq.push(v[x].second);
                prev=v[x].first;
            }
            else{
                if(pq.empty()){
                    flag=1;
                    break;
                }
                
                F=F+pq.top();
                pq.pop();
                ans=ans+1;
                continue;
            }
            
            x++;
        }
        
        if(flag==1){
            cout<<"-1"<<endl;
            continue;
        }
        
        D=D-v[n-1].first;
        if(F>=D){
            cout<<ans<<endl;
            continue;
        }
        
        while(F<D){
            if(pq.empty()){
                flag=1;
                break;
            }
            
            F=F+pq.top();
            pq.pop();
            ans=ans+1;
        }
        
        if(flag==1){
            cout<<"-1"<<endl;
            continue;
        }
        else{
            cout<<ans<<endl;
        }
        
    }
	return 0;
}
