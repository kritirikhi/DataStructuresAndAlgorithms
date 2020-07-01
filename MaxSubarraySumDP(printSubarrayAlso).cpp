#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int,int> maxSubarraySum(int a[],int n){
    int dp[100]={0};
    if(a[0]>=0){
        dp[0]=a[0];
    }
    int maxSoFar=0;
    int maxindex=-1;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+a[i];
        if(dp[i]<0){
            dp[i]=0;
        }
        
        if(dp[i]>maxSoFar){
            maxSoFar=dp[i];
            maxindex=i;
        }
    }
    
    pair<int,int> p;
    p.first=maxSoFar;
    p.second=maxindex;
    
    return p;
    
}

int main() {
    
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    pair<int,int> p = maxSubarraySum(a,n);
    
    int j=p.second;
    int sum=0;
    
    
    vector<int> subarrray;
    while(j>=0){
        subarrray.push_back(a[j]);
        sum=sum+a[j];
        if(sum==p.first){
            break;
        }
        j--;
    }
    
    cout<<"subarrray with maximum sum is:- "<<endl;
    for(int i=subarrray.size()-1;i>=0;i--){
        cout<<subarrray[i]<<" ";
    }
    
    cout<<endl;
    cout<<"Max Sum is "<<p.first;
	return 0;
}
