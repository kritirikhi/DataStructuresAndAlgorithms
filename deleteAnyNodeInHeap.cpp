#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

void downheapify(vector <int> &a,int idx){
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;

    if(leftidx>=a.size() && rightidx>=a.size()){
        return;
    }

    int largestidx=idx;
    if(leftidx<a.size() && a[largestidx]<a[leftidx] ){
        largestidx=leftidx;
    }
    if(rightidx<a.size() && a[largestidx]<a[rightidx] ){
        largestidx=rightidx;
    }
    if(largestidx==idx){
        return;
    }
    swap( a[largestidx] , a[idx] );
    downheapify(a,largestidx);
}

void buildheap(vector <int> &a){
    for(int i=a.size()-1 ; i>=0 ; i--){
        downheapify(a,i);
    }
}

void upheapify(vector <int> &a,int idx){
    if(idx==0){
        return;
    }

    int parentidx=(idx-1)/2;
    if(a[parentidx]<a[idx]){
        swap(a[parentidx] , a[idx] );
        upheapify(a,parentidx);
    }
    else{
        return;
    }
}

void display(vector <int> a){
    int n=a.size();
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;

    vector <int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // building a heap
    buildheap(a);
    display(a);

    // index to be deleted from the heap
    int delidx=1;
    a[delidx]=9999;

    // upheapify the infinity node
    upheapify(a,delidx);

    // swapping the infinity node with the last node of the heap array and popping the infinity the node
    swap(a[0],a[a.size()-1]);
    a.pop_back();

   // downheapify the root node to maintain the heap property
    downheapify(a,0);
    
    display(a);
}