#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2){
    if(p1.second.first==p2.second.first)
        return p1.second.second<p2.second.second;
    return p1.second.first<p2.second.first;
}

int main() {
    int t;
    cin>>t;

    for(int x=0;x<t;x++){
        int n;
        cin>>n;

        vector<pair<int,pair<int,int>>> a;
        for(int i=0;i<n;i++){
            int s,e;
            cin>>s>>e;
            a.push_back(make_pair(i,make_pair(s,e)));
        }

        sort(a.begin(),a.end(),compare);

        int output[n];
        int prevFinishJamie=0;
        int prevFinishCameron=0;

        bool flag=false;
        for(int i=0;i<n;i++){
            if(a[i].second.first >= prevFinishCameron){
                int index=a[i].first;
                output[index]=67;
                prevFinishCameron=a[i].second.second;
            }
            else if(a[i].second.first >= prevFinishJamie){
                int index=a[i].first;
                output[index]=74;
                prevFinishJamie=a[i].second.second;
            }
            else{
                flag=true;
                break;
            }
        }
        if(flag==true){
            cout<<"Case "<<"#"<<x+1<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }
    
        string s;
        for(int i=0;i<n;i++){
            char ch=output[i];
            s.push_back(ch);
        }
        cout<<"Case "<<"#"<<x+1<<": "<<s<<endl;
    }
}
