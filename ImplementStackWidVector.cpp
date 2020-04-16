// We have to implement a stack with vector
#include <iostream>
#include<vector>
using namespace std;

// class stack
// include vector v of integer type as private memeber so that user can't access it directly
// public member functions include :-
//      push()  its adds the element to the back of the vector
//      empty() checks whether the stack is empty or not by finding the size of the vector
//      pop()   it removes element from top of the stack by removing it from the back of the vector using pop_back() func of the vector
//      top()   it returns the top element of the stack which is (size-1)th element of the vector  
class stack{
private:
    vector <int> v;
public:

    void push(int d){
        v.push_back(d);
    }

    bool empty(){
        if(v.size()>0){
            return 1;
        }
        return 0;
    }

    void pop(){
        if(empty()==1){
            v.pop_back();
        }
    }

    int top(){
        return v[v.size()-1];
    }
};

int main() {
    stack s;
    if(s.empty()==0){
        cout<<"stack is empty"<<endl;
    }
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    for(int i=1;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    // output will be :- 25,16,9,4,1
}
