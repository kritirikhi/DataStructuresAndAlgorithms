#include <iostream>
using namespace std;

// creation of class node which includes data and the next pointer
class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

// function to insert at head of the linked list
void insertAtHead(node*&head,int data){
    node*n=new node(data);
    n->next=head;
    head=n;
}

// func to print all the elements of the linked list
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
}

// func returns the middle node of the linked list using runner technique
// there are two pointers (fast,slow)
// fast can take 2 jumps
// slow can take 1 jump
// the moment fast reaches null , the slow pointer is at the mid of the linked list
node* FindMid(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* fast=head->next;
    node* slow=head;
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

int main() {
    node* head=NULL;
    insertAtHead(head,12);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,10);
    insertAtHead(head,18);
    insertAtHead(head,20);

    cout<<"original linked list"<<endl;
    print(head);

    node* mid=FindMid(head);
    cout<<"midpoint of the list is "<<mid->data<<endl;
}
