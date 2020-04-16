// inplementation of stack using STL(standard template library)
// just include stack 
// stack in STL have following functions
//      push()    adding an element in the stack
//      pop()     removing the element from the top of the stack
//      empty()   checks whether the stack is empty or not. returns a boolean
//      top()     returns the top element of the stack
#include <iostream>
#include<stack>
#include<cstring>
using namespace std;
int main() {

    stack<string> s;
    s.push("Apple");
    s.push("Banana");
    s.push("Mango");
    s.push("Pineapple");
    s.push("Guava");
    s.push("Cherry");
    s.push("Strawberry");

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
