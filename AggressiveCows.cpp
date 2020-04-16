// Aggressive Cows Problem
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(int stalls[],int n,int minSep,int cows){
    int prev=stalls[0];
    int count=1;

    for(int i=1;i<n;i++){
        if(stalls[i]-prev>=minSep){
            prev=stalls[i];
            count++;
            if(count==cows){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin>>t;

    for(int x=0;x<t;x++){
        int n,cows;
        cin>>n>>cows;

        int stalls[n];
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        sort(stalls , stalls+n);

        int s=0;
        int e=stalls[n-1]-stalls[0];
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            bool canPlace=canPlaceCows(stalls,n,mid,cows);
            if(canPlace==true){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        cout<<ans<<endl;
    }
}
