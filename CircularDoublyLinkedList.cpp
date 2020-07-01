//                                                          CIRCULAR DOUBLY LINKED LIST IMPLEMENTATION

#include <iostream>
using namespace std;

// class node which stores the elements of the node of the linked list 
class node{
public:
    int data;
    node* next;
    node* prev;
    node(int d){
        data=d;
        next=prev=NULL;
    }
};

// insertion at end of the circular doubly linked list
void insertAtEnd(node* &head,int data){
    // if list is empty then the prev and next pointers will point to the node itself
    if(head==NULL){
        node* n=new node(data);
        head=n;
        n->prev=n;
        n->next=n;
    }

    // otherwise 
    // create the node
    // next pointer of new node will point to the next pointer of the last node
    // prev pointer of new node will point to the last node
    // next pointer of the last node will point to  new node
    // prev pointer of the head will point to the new node
    else{
        node* n=new node(data);
        node* last=head->prev;
        n->next=head;
        n->prev=last;
        last->next=n;
        head->prev=n;
    }
}

// insertion in the beginning of the circular doubly linked list
void insertAtBegin(node* &head,int data){

    // if the list is empty then prev and next pointer of the node will point to itself 
    if(head==NULL){
        node* n=new node(data);
        head=n;
        n->prev=n;
        n->next=n;
    }

    // otherwise
    // create the node
    // next pointer of the new node will point to the first node
    // prev pointer of the new node will point to the last node
    // next pointer of the last node will point to the new node
    // prev pointer of the first node will point to the new node
    // make the new node as the head of the list
    else{
        node* n=new node(data);
        node* last=head->prev;

        n->next=head;
        n->prev=last;
        head->prev=n;
        last->next=n;
        head=n;
    }
}

// insertion of the node after the given target node
void insertAfterTarget(node* &head,int data,int target){

    // find the target node in the list
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            break;
        }
        temp=temp->next;
    }

    // create the new node
    // next pointer of the new node will point to next node of the target node
    // prev pointer of the new node will point to target node
    // prev pointer of the node next to target node will point to new node
    // next pointer of the target node will point to the new node
    node* n=new node(data);
    n->next=temp->next;
    n->prev=temp;
    temp->next->prev=n;
    temp->next=n;
}

// printing of the circular doubly linked list from forward to backward
void print(node* head){
    if(head==NULL){
        return;
    }
    node* temp=head;
    cout<<temp->data<<" ";
    if(temp->next==NULL){
        return;
    }
    temp=temp->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// printing of the circular doubly linked list from backward to forward
void printFromBack(node* head){
    node* end=head->prev;
    node* temp=end;
    cout<<end->data<<" ";

    if(end->prev==NULL){
        return;
    }

    end=end->prev;

    while(end!=temp){
        cout<<end->data<<" ";
        end=end->prev;
    }
}

// main function
int main() {

    // creation of the list
    node* head=NULL;

    // inserting the nodes at the end of the list
    insertAtEnd(head,4);
    insertAtEnd(head,3);
    insertAtEnd(head,2);
    insertAtEnd(head,1);

    // printing the list from forward to backward
    print(head);
    cout<<endl;

    // creation of the list2
    node* head2=NULL;

    // inserting the nodes at the beginning of the list
    insertAtBegin(head2,4);
    insertAtBegin(head2,3);
    insertAtBegin(head2,2);
    insertAtBegin(head2,1);

    // inserting the node after the target node
    insertAfterTarget(head2,5,2);

    // printing the list2 from forward to backward 
    print(head2);
    cout<<endl;

    // printing the list from baackward to forward
    printFromBack(head2);


}
