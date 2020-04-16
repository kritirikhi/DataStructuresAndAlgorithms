//                                                                          QUESTION
// Dean of MAIT is going to visit Hostels of MAIT. As you know that he is a very busy person so he decided to visit only first "K" nearest Hostels. 
// Hostels are situated in 2D plane. You are given the coordinates of hostels and you have to answer the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .

// Input Format
// First line of input contains Q Total no. of queries and K There are two types of queries:

// first type : 1 x y For query of 1st type, you came to know about the co-ordinates ( x , y ) of newly constructed hostel. 
// second type : 2 For query of 2nd type, you have to output the Rocket distance of Kth nearest hostel till now.

// The Dean will always stay at his place ( origin ). It is gauranted that there will be atleast k queries of type 1 before first query of type 2.

// Rocket distance between two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)2 + (y2 - y1)2
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void kthNearestRocketDist(priority_queue<long long int,vector<long long int>,greater<long long int>> minheap,long long int k){
    while(!minheap.empty()){
        if(k==1){
            cout<<minheap.top()<<endl;
            break;
        }
        minheap.pop();
        k--;
    }
}

int main() {
    long long int q,k;
    cin>>q>>k;
    priority_queue<long long int,vector<long long int>,greater<long long int>> minheap;

    for(long long int x=0;x<q;x++){
        long long int type;
        cin>>type;

        if(type==1){
            long long int x,y;
            cin>>x>>y;
            long long int distance= x*x + y*y ;
            minheap.push(distance);
        }
        else if(type==2){
            kthNearestRocketDist(minheap,k);
        }
    }
}
