#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int maxlen=0;
    
    map <int,int> m;
    
    for(int i=0;i<n;i++){
        int len1=0;
        int len2=0;
        if(m[a[i]-1]>0){
            len1=m[a[i]-1];
        }
        if(m[a[i]+1]>0){
            len2=m[a[i]+1];
        }
        
        int newStreakLen=len1+len2+1;
        maxlen=max(maxlen,newStreakLen);
        
        m[a[i]]=newStreakLen;
        
        int lb=a[i]-len1;
        int rb=a[i]+len2;
        if(m.find(lb)!=m.end()){
            m[lb]=newStreakLen;    
        }
        if(m.find(rb)!=m.end()){
            m[rb]=newStreakLen;        
        }
    
    }
    cout<<maxlen;    
    int num=0;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second==maxlen){
            num=it->first;
            break;
        }
    }
    
    cout<<endl;
    cout<<"consecutive subsequence is"<<endl;
    while(maxlen>0){
        cout<<num<<" ";
        num++;
        maxlen--;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	return 0;
}
