// to find kth smallest element from the row and col wise sorted array
// use priority queue(for the better and efficient approach
// for every element at index[row,col] in the matrix the next possible smaller elements are [row,col+1] and [row+1,col]
// pop elements one by one from the heap till we get the kth smallest element
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair< int,pair<int,int> > customPair;

bool findelement( priority_queue< customPair,vector<customPair>,greater<customPair> > minheap,int item){
    while(!minheap.empty()){
        if(minheap.top().first==item){
            return false;
        }
        minheap.pop();
    }
    return true;
}

void kthSmallestElement(vector < vector<int> > a,int k){
    priority_queue<customPair,vector<customPair>,greater<customPair>> minheap;
    minheap.push({a[0][0],{0,0}});

    int ksmallest;

    while(k>0){
        customPair curr=minheap.top();
        minheap.pop();
        ksmallest=curr.first;

        int rowIndex=curr.second.first;
        int colIndex=curr.second.second;

        if(rowIndex+1 < a.size()){
            if(findelement(minheap,a[rowIndex+1][colIndex])){
                minheap.push({ a[rowIndex+1][colIndex], {rowIndex+1,colIndex} });
            }

        }
        if(colIndex+1 < a.size()){
            if(findelement(minheap,a[rowIndex][colIndex+1])){
                minheap.push({ a[rowIndex][colIndex+1],{rowIndex,colIndex+1} });
            }
        }
        k--;
    }
    cout<< ksmallest<<" ";
}

int main() {
    vector < vector<int> > a {
        {10,20,30,40},
        {15,25,35,45},
        {24,29,37,48},
        {32,33,39,50}
    };
    int k;
    cin>>k;
    kthSmallestElement(a,k);
}
