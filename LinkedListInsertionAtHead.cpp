// making the linked list, adding the elements at head and printing the whole linked list
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
    insertAtHead(head,2);
    insertAtHead(head,6);
    print(head);
}
