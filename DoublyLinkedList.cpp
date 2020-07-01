//                                                                  DOUBLY LINKED LIST IMPLEMENTATION

#include <iostream>
using namespace std;

// Class Node which defines the elements of the node of the doubly linked list    
class node{
public:
    node* next;
    node* prev;
    int data;
    node(int d){
        data=d;
        next=prev=NULL;
    }
};

// Adding the node At the head of the doubly linked list 
void insertAtHead(node* &head,int d){
    node* n=new node(d);
    if(head==NULL){
        n->next=NULL;
        n->prev=NULL;
        head=n;
        return;
    }
    n->next=head;
    n->prev=NULL;
    head->prev=n;
    head=n;
}

// Adding the node after the given target node
void addAfterNode(node* &head,int d,node* target){
    node* temp=head;

    while(temp!=NULL){
        if(temp==target){
            break;
        }
        temp=temp->next;
    }

    node* n=new node(d);
    n->next=NULL;
    if(temp->next!=NULL){
         n->next=temp->next;
    }
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
}

// Adding the node before the given target node
void addBeforeNode(node* &head,int d,node* target){
    node* temp=head;
    while(temp!=NULL){
        if(temp==target){
            break;
        }
        temp=temp->next;
    }

    node* n=new node(d);
    n->next=temp;
    n->prev=temp->prev;
    temp->prev->next=n;
    temp->prev=n;
}

// Adding the node at the end of the Doubly Linked List
void addAtEnd(node* &head,int d){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    node* n=new node(d);
    temp->next=n;
    n->next=NULL;
    n->prev=temp;
}


// Printing the doubly linked list from forward and backward
void print(node* head){
    node* temp=head;
    node* last;

    cout<<" Linked list form forward"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        last=temp;
        temp=temp->next;
    }   
    
    cout<<endl;
    cout<<" Linked list from the backward"<<endl;
    while(last!=NULL){
        cout<<last->data<<" ";
        last=last->prev;
    }
}

int main() {

    // head pointer
    node* head=NULL;

    // insertions at head
    insertAtHead(head,4);
    insertAtHead(head,4);
    insertAtHead(head,4);
    insertAtHead(head,4);
    insertAtHead(head,4);

    // adding the node after the given target node
    node* target=head->next->next;
    addAfterNode(head,5,target);

    // adding the node at end
    addAtEnd(head,9);
    
    // adding the node before the given target node
     node* target2=head->next->next->next;
     addBeforeNode(head,3,target2);

    // printing the linked list from forward and backward
    print(head);
}
