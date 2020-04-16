// implementing stack functionality using 2 queues
#include <iostream>
#include<queue>
using namespace std;

// approach1 ==================>>>        MAKING POP OPERATION COSTLY          ====================================
// use two queues q1,q2
// push operation:-
//      all the elements will be pushed in q1
// pop operation:-
//      n-1 elements will poped from q1 and pushed in q2
//      the nth element will be poped and not entered in q2
//      swap both queues so that definition remain same
// top:-
//      same as the pop operation
//      but the nth element will be returned and pushed in q2
//      and then agan swap both the queues so that definition remain same
class stack{
    queue<int> q1,q2;

public:
    void push(int x){
        q1.push(x);
    }

    void pop(){
        int n=q1.size();
        for(int i=0;i<n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        if(!q1.empty()){
            q1.pop();
        }
        swap(q1,q2); 
    }

    int top(){
        int n=q1.size();
        for(int i=0;i<n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int topElement=q1.front();

        if(!q1.empty()){
            q2.push(q1.front());
            q1.pop();  
        }
        swap(q1,q2); 
        return topElement;
    }
};

// approach2 ==================>>>        MAKING PUSH OPERATION COSTLY          ====================================
// push operation:-
//      put the element to be pushed in q2 
//      pop all elements of q1 and push them to q2
//      swap q1,q2
// pop operation:-
//      pop the front element of the q1
// top:-
//      return the front element of q1

class stack2{
    queue<int> q1,q2;

public:
    void push(int x){
        q2.push(x);
        int n=q1.size();
        for(int i=0;i<n;i++){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    void pop(){
        q1.pop();
    }

    int top(){
        return q1.front();
    }
};

int main() {
    stack2 s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
   
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}
