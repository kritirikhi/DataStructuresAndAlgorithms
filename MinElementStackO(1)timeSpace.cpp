#include <iostream>
using namespace std;

class stack{
int a[1000];
int i;
int cs;
int curr_min;
public:
    stack(){
        curr_min=0;
        cs=0;
        i=0;
    }

    bool empty(){
        return cs==0;
    }

    void push(int x){
        if(empty()){
            curr_min=x;
            a[i]=x;
            i++;
            cs++;
        }

        else if(x<curr_min){
            a[i]=2*x-curr_min;
            curr_min=x;
            i++;
            cs++;
        }
        else if(x>curr_min){
            a[i]=x;
            i++;
            cs++;
        }

    }
    
    void pop(){
        int y=top();
        if(y < curr_min){
            curr_min= 2*curr_min-y;
        }
        i--;
        cs--;
    }

    int top(){
        return a[cs-1];
    }

    int getMin(){
        return curr_min;
    }
    int curr_size(){
        return cs;
    }
};

int main() {
    stack s;
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);

    cout<<s.getMin()<<endl;

    s.pop();
   

    cout<<s.getMin();

}
