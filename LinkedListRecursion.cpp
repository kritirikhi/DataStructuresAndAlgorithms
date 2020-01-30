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

// function to reverse the linked list recursively
// we will assume that recursion will return reversed list (smaller problem)
node* reverseRecursive(node* &head){
    // base case 
    if(head==NULL || head->next==NULL){
        return head;
    }

    // rec case
    node* newHead=reverseRecursive(head->next);
    node* c=head;
    c->next->next=c;
    c->next=NULL;
    return newHead;
}

// func to print all the elements of the linked list
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
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

    cout<<"reversed linked list"<<endl;
    head=reverseRecursive(head);
    print(head);

}
