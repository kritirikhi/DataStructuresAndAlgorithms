#include <bits/stdc++.h>
using namespace std;

#define ll long long 

// Introduce the concept of finding subsequences using bitmasks 


// v = {1,2,3,4,7}
// output is vector of subset sums
vector<ll> subsets(vector<ll> v){
    
    vector<ll> ans;
    ans.clear();
    
    int n = v.size();
    
   
    for(int i=0;i < (1<<n);i++){
        
        //Extract the bits of the current no 
        int j = 0;
        ll sum = 0 ;
        
        for(int no = i; no>0; no = no>>1){
            if(no&1){
                 //ns.push_back(v[j]);
                 sum += v[j];
                 
            }
            j++;
        }
        ans.push_back(sum);
    }
    return ans;
}




int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    
    int n1 = n/2; //First Set
    int n2 = n - n1; // Second Set

    vector<ll> v1,v2;
    
    //v1, v2  Input 
    for(int i=0;i<n1;i++){
        ll x;
        cin>>x;
        v1.push_back(x);
    }
    
    for(int i=0;i<n2;i++){
        ll x;
        cin>>x;
        v2.push_back(x);
    }
    
    //Sum of Subset of Vector v1 and v2;
    vector<ll> sv1, sv2;
    
    sv1 = subsets(v1);
    sv2 = subsets(v2);
    
    //sort(sv1.begin(),sv1.end());
    sort(sv2.begin(),sv2.end());
    
    ll ans = 0;
    //Matching using Binary Search 
    //subsets
    /*
    for(int i : sv2){
        cout<<i<<",";
    }
    cout<<endl;
    */

    for(int i=0;i<sv1.size();i++){
        
        ll st = a - sv1[i];
        ll en = b - sv1[i];
        
        auto it1 = lower_bound(sv2.begin(),sv2.end(),st);
        auto it2 = upper_bound(sv2.begin(),sv2.end(),en);
        ll l = it2 - sv2.begin();
        ll k = it1 - sv2.begin();
        //cout<<sv1[i]<<" + "<<sv2[l]<<" , "<<sv2[k]<<endl;

        ans += (l - k );
        //cout<<ans<<endl;
        
    }
    cout<<ans<<endl;
}
