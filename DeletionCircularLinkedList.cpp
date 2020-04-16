// inserting element and traversing elements in circular linked list 
#include <iostream>
using namespace std;

// creating class node consisting of data and next pointer 
class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
    }
};

// function which inserts element at the head of the node
// create new node with the data
// if head is null then the next pointer of the new node will point to itself only as new node is the first node of the circular linked list
// if head is not null then the next pointer of this new node will point to the head of the circular linked list
// we will find the tail node using temp node and temp->next = new node created
// at last head will point to the new node created
void insertAtHead(node*&head,int data){
    node* n=new node(data);
    if(head==NULL){
        n->next=n;
    }
    else{
        n->next=head;
        node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
    }
    head=n;
}

// func returns node which is to be deleted by the user
// if node not present then return null
node* getnode(node*&head,int data){
    node *temp=head;
    while(temp->next!=head){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    if(temp->data==data){
        return temp;
    }
    return NULL;
}

// func actually delete the node
// 1st the node (del) to be deleted is found out by getNode func
// if returned node is NULL then return as node is not present
// if returned node is equal to the head of the LL then head=del->next and tailNode->next=del->next and then delete del node
// if returned node is in between the LL then find the previous position and then prev->next=del->next and then delete del node
void deleteNode(node*&head,int data){
    node *del=getnode(head,data);
    if(del==NULL){
        cout<<" node is not present "<<endl;
        return;
    }
    
    else if(del==head){
        head=del->next;
    }

    node*temp=head;
    while(temp->next!=del){
        temp=temp->next;
    }
    temp->next=del->next;
    delete del;
}

// function to print all the elements of the linked list by traversing the linked list
void print(node* head){
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

int main() {
    node *head=NULL;
    insertAtHead(head,23);
    insertAtHead(head,24);
    insertAtHead(head,25);
    insertAtHead(head,26);
    insertAtHead(head,27);
    cout<<"original linked list"<<endl;
    print(head);

    deleteNode(head,25);
    cout<<"linked list after deletion operation"<<endl;
    print(head);
}
