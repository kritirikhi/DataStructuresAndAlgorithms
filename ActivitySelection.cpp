#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int main() {
	int t;
	cin>>t;

	for(int x=0;x<t;x++){
		int n;
		cin>>n;

		vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            int s,e;
            cin>>s>>e;
            a.push_back(make_pair(s,e));
        }

		sort(a.begin(),a.end(),compare);
     
		int count=1;
        int prevFinish=a[0].second;
		for(int i=1;i<n;i++){
            if(a[i].first>=a[i-1].second){
                count++;
                prevFinish=a[i].second;
            }
		}
        cout<<count;
	}
	return 0;
}

