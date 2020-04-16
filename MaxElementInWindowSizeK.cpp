// to find the max element in every window of size K
#include <iostream>
#include<deque>
using namespace std;

// use dqueue data structure
// for every element in the array we will check the max possible element to be added in dequeue 
// dequeue will have the elements in descending order
// dequeu will store only indexes 
void maxElementInWindow(int a[],int n,int k){
    deque <int> dq;
    int i;
    for(i=0;i<k;i++){
        while(!dq.empty() and a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(;i<n;i++){
        cout<<a[dq.front()]<<"  ";
        while(!dq.empty() and dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() and a[i]>=a[dq.front()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<a[dq.front()];
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    maxElementInWindow(a,n,k);
}
