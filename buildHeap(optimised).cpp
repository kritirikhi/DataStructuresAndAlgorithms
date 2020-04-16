// BUILD HEAP
// given an array of random numbers 
// arrange them in order that they satisfy the property of the heap
// EFFICIENT APPROACH:-
//      at ith index we will assume that all the elements from (i+1) to (n-1) indexes are already in heap
//      this will take O(n) time (OPTIMISED) coz lesser operations are to be performed at lower levels(more numbers of nodes) 
//      and more operations are to be performed for the higher levels(lesser no of nodes)
//      DOWNHEAPIFICATION is used from last of the array to the 0th index of the array
#include <iostream>
using namespace std;

void downheapify(int a[],int idx,int n){
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;

    if(leftidx>=n && rightidx>=idx){
        return;
    }

    int largestidx=idx;
    if(leftidx<n && a[largestidx]<a[leftidx]){
        largestidx=leftidx;
    }
    if(rightidx<n && a[largestidx]<a[rightidx]){
        largestidx=rightidx;
    }
    if(largestidx==idx){
        return;
    }
    swap(a[largestidx],a[idx]);
    downheapify(a,largestidx,n);
}


void buildHeapOptimised(int a[],int n){
    for(int i=n-1;i>=0;i--){
        downheapify(a,i,n);
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

    buildHeapOptimised(a,n);
    display(a,n);
}
