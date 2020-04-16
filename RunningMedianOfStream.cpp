// TO CALCULATE THE MEDIAN OUT OF THE RUNNING STREAM
// Approach :-
//      Use priority queues (maxheap,minheap)
//      maxheap will store the element smaller than the current median
//      minheap will store the element greater than the current median
//      we have to maintain the balanced heaps i.e maxheap Height - minheap height <=1
//      if maxheap.size()>minheap.size() median = maxheap.top()
//      if minheap.size()>maxheap.size() median = minheap.top()
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // priority queues
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;

    maxheap.push(a[0]);
    int median;
    for(int i=1;i<n;i++){
        // calc the median
        if( maxheap.size()==minheap.size() ){
            median=( maxheap.top()+minheap.top() )/2;
        }
        else if( maxheap.size()>minheap.size() ){
            median=maxheap.top();
        }
        else if( maxheap.size()<minheap.size() ){
            median=minheap.top();
        }
        // printing the current median
        cout<<median<<" ";

        // updating the max and min heaps with the current data in the array (stream)
        if(a[i]>median){
            minheap.push(a[i]);

            if(minheap.size()-maxheap.size()>1){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        
        if(a[i]<median){
            maxheap.push(a[i]);
            if(maxheap.size()-minheap.size()>1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }

    }

    // calc the median for the last data of the stream
    if( maxheap.size()==minheap.size() ){
            median=( maxheap.top()+minheap.top() )/2;
    }
    else if( maxheap.size()>minheap.size() ){
        median=maxheap.top();
    }
    else if( maxheap.size()<minheap.size() ){
        median=minheap.top();
    }
    cout<<median;
}
