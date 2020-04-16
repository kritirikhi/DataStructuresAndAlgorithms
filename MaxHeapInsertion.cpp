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
}
