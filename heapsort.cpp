//  HEAPSORT
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void downheapify(vector<int> &a , int idx){
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;

    if(leftidx>=a.size() && rightidx>=a.size()){
        return;
    }

    int largestidx=idx;
    if(leftidx<a.size() && a[leftidx]>a[largestidx] ){
        largestidx=leftidx;
    }
    if(rightidx<a.size() && a[rightidx]>a[largestidx] ){
        largestidx=rightidx;
    }
    if(largestidx==idx){
        return;
    }
    swap(a[largestidx],a[idx]);
    downheapify(a,largestidx);
    
}

void buildheap(vector<int> &a){
    for(int i=a.size()-1 ; i>=0 ; i--){
        downheapify(a,i);
    }
}

void downheapifyHelper(vector<int> &a , int idx, int heap_size){
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;

    if(leftidx>=heap_size && rightidx>=heap_size){
        return;
    }

    int largestidx=idx;
    if(leftidx<heap_size && a[leftidx]>a[largestidx] ){
        largestidx=leftidx;
    }
    if(rightidx<heap_size && a[rightidx]>a[largestidx] ){
        largestidx=rightidx;
    }
    if(largestidx==idx){
        return;
    }
    swap(a[largestidx],a[idx]);
    downheapifyHelper(a,largestidx,heap_size);
    
}

// performs the sorting oprations
//      swap the root with the last element
//      reduce the size of the heap
//      perform downheapification using downheapifyHelper() func
//      the above three operations continue for all the elements of the heap
void heapsort(vector<int> &a){
    int heap_size=a.size();
    for(int i=a.size()-1;i>=0;i--){
        swap(a[0],a[i]);
        heap_size--;
        downheapifyHelper(a,0,heap_size);
    }

}


// to print the elements of the array
void display(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    // size of the heap
    int n=8;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // buildig heap from the array
    buildheap(a);
    cout<<"original elements of the heap :- "<<endl;
    display(a);

    // performing the heapsort
    heapsort(a);
    cout<<"sorted elements of the heap :- "<<endl;
    display(a);
}
