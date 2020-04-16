// given the points on the 2d plane
// we have to calculate the total no of right angled triangles possible with base and perpendicular parallel to the x or y axis

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int calcRytTriangles(vector<int> a, vector<int> b) {
    unordered_map<int,int> mx;
    unordered_map<int,int> my;
    
    for(int i=0;i<a.size();i++){
        mx[a[i]]++;
        my[b[i]]++;
    }
    
    long long int count=0;
    for(int i=0;i<a.size();i++){
        long long int n1=mx[a[i]];
        n1=n1%1000000007;
        long long int n2=my[b[i]];
        n2=n2%1000000007;
        
        count+=((n1-1)%1000000007)*((n2-1)%1000000007);
    }
    return count;
}

int main() {
    int n;
    cin>>n;

    vector <int> a(n);
    vector <int> b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
   
    cout<<calcRytTriangles(a,b);
}
