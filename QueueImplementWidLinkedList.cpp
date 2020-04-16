#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

class queue{
node *head;
int cs;
public:
    queue(){
        head=NULL;
        cs=0;
    }

    bool empty(){
        return cs==0;
    }

    void push(int x){
        if(empty()){
            node *n= new node(x);
            n->next=head;
            head=n;
            cs++;
        }
        else{
            node*temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new node(x);
        }
        
    }

    void pop(){
        if(!empty()){
            node*temp=head;
            head=temp->next;
            delete temp;
            cs--;
        }
    }

    int getFront(){
        return head->data;
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
