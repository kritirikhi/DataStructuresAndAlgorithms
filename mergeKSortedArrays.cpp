//      MERGE K SORTED ARRAYS (using priority queue)
// Approach
//      If there are k sorted arrays then we will make a heap of size K
//      the heap will first store the 0th index of all k arrays in it
//      repeat the following till heap is not empty
//          pop the top of the heap
//          add the element to the resultant vector
//          then push the element of that array from which the prev element from heap is popped
//      complexity O(nklogk)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int , pair<int,int> > customPair;

vector<int> mergeKsortedArrays(vector< vector<int> > a){
    priority_queue<customPair,vector<customPair>,greater<customPair>> minheap;
    for(int i=0;i<a.size();i++){
        minheap.push({a[i][0],{i,0}});
    }

    vector<int> result;
    while(!minheap.empty()){
        customPair curr=minheap.top();
        minheap.pop();
        
        int arrindex=curr.second.first;
        int eleindex=curr.second.second;
        
        result.push_back(curr.first);

        if( (eleindex+1) < a[arrindex].size() ){
            minheap.push({a[arrindex][eleindex+1],{arrindex,eleindex+1}});
        }
    }
    return result;
}

int main() {
    vector < vector<int> > a {
        {2,6,12,15},
        {1,9,13,15},
        {20,24,30,32},
        {1,1,1,1}
    };

    vector <int> output = mergeKsortedArrays(a);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }

}
