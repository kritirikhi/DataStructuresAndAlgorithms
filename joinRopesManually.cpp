//                                                                  JOIN ROPES (manually by makin the heap)
//      QUESTION:-
//          given n ropes of diff sizes.Cost of joining the ropes(a,b) is a+b. join the ropes such that the total cost is minimum to make all the ropes into one.

//      APPROACH
//          take first minimum from the minheap and pop it out of heap
//          take second minimum from the minheap and pop it out of heap
//          add min1+min2 to the cost
//          push/insert the min1+min2 to the minheap
#include <iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

void downheapify(vector<int> &a , int idx){
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;

    if(leftidx>=a.size() && rightidx>=a.size()){
        return;
    }

    int smallestidx=idx;
    if(leftidx<a.size() && a[leftidx]<a[smallestidx] ){
        smallestidx=leftidx;
    }
    if(rightidx<a.size() && a[rightidx]<a[smallestidx] ){
        smallestidx=rightidx;
    }
    if(smallestidx==idx){
        return;
    }
    swap(a[smallestidx],a[idx]);
    downheapify(a,smallestidx);    
}

void buildheap(vector<int> &a){
    for(int i=a.size()-1 ; i>=0 ; i--){
        downheapify(a,i);
    }
}


void upheapify(vector <int>&heap, int index ){
    if(index==0){
        return;
    }
    int parentIndex=(index-1)/2;
    if(heap[parentIndex] > heap[index] ){
        int temp=heap[parentIndex];
        heap[parentIndex]=heap[index];
        heap[index]=temp;
        upheapify(heap,parentIndex);
    }
    else{
        return;
    }
}

void joinRopes(vector <int> &a,int &cost){
    if(a.size()==1){
        cout << cost;
        return;
    }
    int min1=a[0];
    swap(a[0],a[a.size()-1]);
    a.pop_back();

    downheapify(a,0);

    int min2=a[0];
    swap(a[0],a[a.size()-1]);
    a.pop_back();

    cost=cost+min1+min2;

    downheapify(a,0);

    a.push_back(min1+min2);
    upheapify(a,a.size()-1);

    joinRopes(a,cost);
    
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
    int n=4;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // building heap from the array
    buildheap(a);
    cout<<"original elements of the heap :- "<<endl;
    display(a);

    // finding cost required to join the ropes to one
    int cost=0;
    cout<<"the min cost required to join all the ropes together is:- "<<endl;
    joinRopes(a,cost);

}
