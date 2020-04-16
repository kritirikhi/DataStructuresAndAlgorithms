// BUILD HEAP
// given an array of random numbers 
// arrange them in order that they satisfy the property of the heap
// APPROACH:-
//      at ith index we will assume that all the elements from 0-(i-1) indexes are already in heap
//      this will take O(nlogn) time (UNOPTIMISED) coz more operations are to be performed at lower levels(more numbers of nodes) 
//      and least operations are to be performed for the higher levels(lesser no of nodes)
#include <iostream>
using namespace std;

void upheapify(int a[],int idx){
    if(idx==0){
        return;
    }
    int parentIdx=(idx-1)/2;
    if(a[parentIdx]<a[idx]){
        swap(a[parentIdx],a[idx]);
        upheapify(a,parentIdx);
    }
    else{
        return;
    }
}

void buildHeap(int a[],int n){
    for(int i=0;i<n;i++){
        upheapify(a,i);
    }
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    buildHeap(a,n);
    display(a,n);
}
