//                                                                   BUILDING MAXHEAP
#include <iostream>
#include<vector>
using namespace std;


// fucnction which performs upheapify process for every element till root node(worst case)
void upheapify(vector <int>&heap, int index ){
    if(index==0){
        return;
    }
    int parentIndex=(index-1)/2;
    if(heap[parentIndex] < heap[index] ){
        int temp=heap[parentIndex];
        heap[parentIndex]=heap[index];
        heap[index]=temp;
        upheapify(heap,parentIndex);
    }
    else{
        return;
    }
}


// inserts the element one by one in the heap
void insertHeap(vector <int> &heap,int item){
    heap.push_back(item);
    upheapify(heap,heap.size()-1);
}

// printing the heap vector
void display(vector <int> &heap){
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

// func which down heapify the heap wwhen the element is deleted from the heap
void downHeapify(vector<int> &heap,int idx){
    int leftidx=2*idx+1;
    int rightidx=2*idx+2;

    if(leftidx >= heap.size() && rightidx >= heap.size()){
        return;
    } 

    int largestidx=idx;
    if(leftidx < heap.size() && heap[leftidx] > heap[largestidx]){
        largestidx=leftidx;
    }
    if(rightidx < heap.size() && heap[rightidx] > heap[largestidx]){
        largestidx=rightidx;
    }

    if(largestidx==idx){
        return;
    }

    swap(heap[largestidx],heap[idx]);
    downHeapify(heap,largestidx);
}

// deletion of the peek element by swapping it with last level rightmost element and then deleting it (popping back)
void deletePeek(vector<int> &heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap,0);
}

int main() {
    int n;
    cin>>n;

    vector <int> heap;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertHeap(heap,x);
    }
    display(heap);
    deletePeek(heap);
    display(heap);
}
