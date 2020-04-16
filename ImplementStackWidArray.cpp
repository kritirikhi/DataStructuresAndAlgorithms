// We have to implement a stack with array
#include <iostream>
using namespace std;
 
// class stack
// include array a of integer type, t which denotes top of the stack as private memeber so that user can't access it directly
// public member functions include :-
//      push()  its adds the element to the back of the array
//      empty() checks whether the stack is empty or not by finding the value of t. if t=0 then array is empty hence, sack empty
//      pop()   it removes element from top of the stack by removing it from the back of the array by decrementing the t i.e top of the stack
//      top()   it returns the top element of the stack which is value of (t-1)th index of the array
class stack{

private:
    int a[1000];
    int t;

public:
    
    stack(){
        t=0;
    }

    void push(int data){
        a[t]=data;
        t++;
    }

    bool empty(){
        if(t==0){
            return 0;
        }
        return 1;
    }

    void pop(){
        if(empty()==1){
            t--;
        }
    }

    int top(){
        return a[t-1];
    }
    
    void isFull(){
        if(t>=1000){
            cout<<"stack is full"<<endl;
        }
        else{
            cout<<"stack is not full"<<endl;
        }
    }

};

int main() {
    stack s;
    for(int i=1;i<=1000;i++){
        s.push(i);
    }
    s.isFull();

    for(int i=1;i<=10;i++){
        cout<<s.top()<<endl;
        s.pop();
    }

    s.isFull();
    // s.isEmpty();
    // s.push(4);
    // s.isEmpty();
}
