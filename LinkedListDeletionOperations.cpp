// to perform deletion operations at head , middle and tail of the linked list
#include <iostream>
using namespace std;

// defining the node class having the data and next pointer
class node{
public:
    int data;
    node* next;

    node(int d){
        data=d;
        next=NULL;
    }
};

// function to find the no of elements in the linked list
int length(node* head){
    int len=0;
    while(head!=NULL){
        len++;
    }
    return len;
}

// function to insert the elements at the head
void insertAtHead(node* &head,int data){
    node* n=new node(data);
    n->next=head;
    head=n;
}

// function to delete the first element(element at head) of the linked list
// just make temp node = head node , move the next pointer of the head to 2nd node and delete the temp node
void deleteAtHead(node* &head){
    if(head==NULL){
        return;
    }
    node* temp=head;
    head=head->next;
    delete temp;
}

// function to perform deletion operation at tail of the linked list
// we will find the node prev to the node at last
// delete the ;ast node and set next of rev node to NULL
void deleteAtTail(node* head){
    if(head==NULL){
        return;
    }
    node* temp=head;
    node* prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next=NULL;
}


// function to delete the element from the middle of the linked list
// find the prev node and perform same operaton as performed in deleteAtTail
void deleteAtMiddle(node* head,int p){
    if(head==NULL){
        return;
    }
    else if(p>length(head)){
        deleteAtTail(head);
    }
    else{
        int j=1;
        node*temp=head;
        node*prev;
        while(j<=p-1){
            prev=temp;
            temp=temp->next;
            j++;
        }
        prev->next=temp->next;
        delete temp;
    }
}

// function to print all the elements of the linked list
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    node* head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,1);
    insertAtHead(head,3);
    insertAtHead(head,5);
    insertAtHead(head,20);
    insertAtHead(head,10);
    insertAtHead(head,11);
    insertAtHead(head,15);

    cout<<"list before deletion"<<endl;
    print(head);

    deleteAtHead(head);
    cout<<"list after deletion at head"<<endl;
    print(head);

    deleteAtTail(head);
    cout<<"list after deletion at tail"<<endl;
    print(head);

    deleteAtMiddle(head,3);
    cout<<"list after deletion in middle at position 3"<<endl;
    print(head);
}
