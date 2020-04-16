// to detect the presence of cycle in linked list and to remove that cycle
// using floyd algorithm for cycle detection and cycle removal
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
    cout<<endl;
}

// the function detect the presence of the cycle using runner technique
// the two pointers fast and slow are created equal to head
// fast will take 2 jumps and slow will take 1 jump
// if cycle does not exist the loop completes and return false
// if cycle exist then fast will become equal to slow at some point of time and then func will return true
bool detectloop(node* &head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

// function to remove cycle from the linked list
// the moment fast becomes equal to slow , the loop breaks
// iterate again takin slow from head and fast from the position where slow==fast
// the moment slow==fast again is the node which initiate the cycle
// make the node prev to the node initiating the cycle to point null
void removeCycle(node*head){
    node*fast=head;
    node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            break;
        }
    }
    slow=head;
    node*prev;
    while(fast!=slow){
        prev=fast;
        fast=fast->next;
        slow=slow->next;
    }
    prev->next=NULL;
}

int main() {
    node* head=NULL;
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    cout<<"original linked list is"<<endl;
    print(head);

    head->next->next->next->next->next->next->next=head->next->next;   // creating a cycle in linked list
    
    
    if(detectloop(head)){
        cout<<"yes cycle exists in linked list"<<endl;
        removeCycle(head);
        cout<<"linked list after cycle removal"<<endl;
        print(head);
    }
    else{
        cout<<"no cycle does not exist in linked list"<<endl;
    }
}
