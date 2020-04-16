// reversing a stack by recursion
// top element of the stack has to be put at the bottom of the same stack
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int x){
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int y=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(y);
}

void reverseRec(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }

    int x=s.top();
    s.pop();
    reverseRec(s);
    insertAtBottom(s,x);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseRec(s);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();


}
