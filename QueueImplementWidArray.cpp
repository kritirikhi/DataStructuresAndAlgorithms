// implementation of queue using fixed size dynamic array
// queue is a first in first out data structure
// the elements are added from the end and are removed from the front end just as the people in a queue for waiting for buying the ticket at reservation center
// we make the followig functions in the templated class queue
//  push()        adding elements at the rear end 
//  pop()         removing the elements from the front end
//  isFull()      to check whether the queue is full or not. It returns the boolean
//  isEmpty()     to cheeck whether the queue is empty or not. It also returns the boolean
//  getFront()    it returns the front element of the queue

// this is the implementation of the circular queue as when rear comes to the last index of  the array we can add the element at (r+1)%n th index if the queue is not empty

#include <iostream>
using namespace std;

template <typename T>
class queue{
    T *arr;
    int f;
    int r;
    // ms is the max size of the queue
    // cs is the current size of the queue
    int cs;
    int ms;

public:
    queue(int ds=5){
        f=0;
        ms=ds;
        cs=0;
        r=0;
        arr=new T[ms];
    }

    bool isFull(){
        return cs==ms;
    }

    bool isEmpty(){
        return cs==0;
    }

    void push(T data){
        if(!isFull()){
            arr[r]=data;
            r=(r+1)%ms;
            cs++;
        }
    }

    void pop(){
        if(!isEmpty()){
            f=(f+1)%ms;
            cs--;
        }
    }

    T getFront(){
        return arr[f];
    }

};

int main() {

    queue<int> q(7);
    for(int i=1;i<=7;i++){
        q.push(i);
    }

    q.pop();
    q.pop();
    q.push(8);

    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }

    return 0;
}
