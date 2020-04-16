#include <iostream>
#include<list>
using namespace std;

class queue{
int cs;
list<int> q;
public:
    queue(){
        cs=0;
    }

    bool empty(){
        return cs==0;
    }

    void push(int x){
        q.push_back(x);
        cs++;
    }

    void pop(){
        if(!empty()){
            q.pop_front();
            cs--;
        }
    }

    int getFront(){
        return q.front();
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    q.pop();

    cout<<q.getFront();
}
