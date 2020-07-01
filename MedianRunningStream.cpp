//                                                                   MEDIAN OF THE RUNNING STREAM

#include <bits/stdc++.h>
using namespace std;

void RunningMedian(vector<int> v){
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int,vector<int>> maxheap;
    
    maxheap.push(v[0]);
    cout<<v[0]<<" ";
    
    double cmedian1=maxheap.top();
    if(v[1]<cmedian1){
        int top=maxheap.top();
        maxheap.pop();
        maxheap.push(v[1]);
        minheap.push(top);
        cout<<(minheap.top()+maxheap.top())/2<<" ";
    }
    else{
        minheap.push(v[1]);   
        cout<<(minheap.top()+maxheap.top())/2<<" ";
    }
   
    for(int i=2;i<v.size();i++){
        int num=v[i];
        int minheapSize=minheap.size();
        int maxheapSize=maxheap.size();
        
        double cmedian;
        
        if(minheapSize==maxheapSize){
            cmedian=(minheap.top()+maxheap.top())/2.0;
            if(num>cmedian){
                minheap.push(num);
                cout<<minheap.top()<<" ";
            }
            else{
                maxheap.push(num);
                cout<<maxheap.top()<<" ";
            }
        }
        
        else if(maxheapSize>minheapSize){
            cmedian=maxheap.top();
            if(num>cmedian){
                minheap.push(num);
                cout<<(minheap.top()+maxheap.top())/2<<" ";
            }
            else{
                int top=maxheap.top();
                maxheap.pop();
                maxheap.push(num);
                minheap.push(top);
                cout<<(minheap.top()+maxheap.top())/2<<" ";
            }
        }
        else if(minheapSize>maxheapSize){
            cmedian=minheap.top();
            if(num<cmedian){
                maxheap.push(num);
                cout<<(minheap.top()+maxheap.top())/2<<" ";
            }
            else{
                int top=minheap.top();
                minheap.pop();
                minheap.push(num);
                maxheap.push(top);
                cout<<(minheap.top()+maxheap.top())/2<<" ";
            }
        }
        
        // cout<<cmedian<<" ";
        
    }
    
    // if(minheap.size()==maxheap.size()){
    //     cout<<(minheap.top()+maxheap.top())/2<<" ";
    // }
    // else if(maxheap.size()>minheap.size()){
    //     cout<<maxheap.top()<<" ";
    // }
    // else{
    //     cout<<minheap.top()<<" ";
    // }
    
    
}

int main() {
    int t;
    cin>>t;
    
    for(int x=0;x<t;x++){
        int n;
        cin>>n;
        
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        
        if(n==1){
            cout<<v[0]<<endl;
            continue;
        }
        if(n==2){
            cout<<v[0]<<" "<<(v[0]+v[1])/2<<endl;
            continue;
        }
        
        RunningMedian(v);
        cout<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	return 0;
}
