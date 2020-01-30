// making the linked list, adding the elements at head,middle,last of the liked list and printing the whole linked list after the operations
#include <iostream>
using namespace std;

// defining the class node which includes data and pointer which points to next node
class node{
public:
    int data;
    node* next;

    node(int d){
        data=d;
        next=NULL;
    }
};

// the function inserts the element at head and accepts the head pointer by reference in order to make changes in head node
// the new node (n) is created dynamically in order to avoid the deletion of the node after function call ends
// the new node will contain data to be inserted
// the next pointer of the node n will point to the node pointed by head
// the head will point to the node n 
void insertAtHead(node* &head,int data){
    node* n=new node(data);
    n->next=head;
    head=n;
}

// function returning no of elements of linked list
int length(node*head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}

// func adding the element at the last of the linked list
// making node temp=head and by using loop we will take tempto the last node
// adding the new node n at the last 
void insertAtTail(node*&head,int data){
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(data);
}

// adding the element in the middle of the linked list
// if head==null or position=0 then element is to be added at the head so call head function
// if position>no of elements the add the element at the last of the linked list
// for adding element in the middle , we have to find the node already present at that position. for that we need to take (position-1) jumps.
//    example:- for adding element at 3rd pos we need 2 jumps to reach the node already present at 3rd position
// after finding node already present,  make a new node and link it to the next node and prev node is to be linked with new node 
void insertInMiddle(node* &head,int data,int p){
    if(head==NULL || p==0){
        insertAtHead(head,data);
    }
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        int jump=1;
        node* temp=head;
        while(jump<=p-1){
            temp=temp->next;
            jump+=1;
        }
        node* n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

// the function performs the printing of the linked list
// the printing takes place until head becomes null
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
}

int main() {
    node* head=NULL;
    //node* head=new node(2);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtTail(head,6);
    insertInMiddle(head,2,3);
    print(head);
}
