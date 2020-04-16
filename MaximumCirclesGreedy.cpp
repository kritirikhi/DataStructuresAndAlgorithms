//                                          MAXIMUM CIRCLES PROBLEM
// We are given n circles lying on x axis. We know the center (x,0) and the radius. Find the minimum no of circles which are needed
// to be removed in order to avoid overlapping of the circles (touching is also overlapping


// Approach
//  find the starting and ending points of the diameter as (x-r) (x+r)
//  sort the pairs acc to the end point
//  traverse the array
//      if the start point of any circle is less than or equal to end point of prev circle then remove that circle
//      else just change the prev end point as end point of current circle
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long int,long long int> p1,pair<long long int,long long int> p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second<p2.second;
}

int main() {
    long long int n;
    cin>>n;

    vector<pair<long long int,long long int>> v;
    for(long long int i=0;i<n;i++){
        long long int c,r;
        cin>>c>>r;
        
        long long int s=c-r;
        long long int e=c+r;
        v.push_back(make_pair(s,e));
    }

      sort(v.begin(),v.end(),compare);

      long long int ans=0;
      long long int prevEnd=v[0].second;

      for(long long int i=1;i<n;i++){
          if(v[i].first < prevEnd){
              ans++;
          }
          else{
              prevEnd=v[i].second;
          }
      }
      
      cout<<ans;
}
