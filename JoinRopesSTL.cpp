//                                                                JOIN ROPES USING STL (PRIORITY QUEUE)
//  make a minheap(priority queue) using the array input by the user
//  1st minimum val=minheap.top();
//  pop out this 1st minimum val
//  2nd minimum val=minheap.top();
//  pop out this 2nd minimum val
//  add min1+min2 to the cost
//  insert(push) min1+min2 to the minheap
#include <iostream>
#include<queue>
using namespace std;

int joinRopes(int a[],int n){
    int cost=0;
    priority_queue <int, vector<int>, greater<int>> minheap(a,a+n);
    while(minheap.size()!=1){
        int min1=minheap.top();
        minheap.pop();
        int min2=minheap.top();
        minheap.pop();

        cost=cost+min1+min2;
        minheap.push(min1+min2);
    } 
    return cost;
}


int main() {
    int n=4;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"the min cost required to join all the ropes together is :- ";
    cout<<joinRopes(a,n);
}
