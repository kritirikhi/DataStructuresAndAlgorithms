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

// function to insert the elements at the head
void insertAtHead(node* &head,int data){
    node* n=new node(data);
    n->next=head;
    head=n;
}

// function to insert node at last
void insertAtLast(node* &head,int d){
    if(head==NULL){
        insertAtHead(head,d);
    }
    else{
        node * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node(d);
    }

}

// function to take input data and adding the elements at the end of the linked list
void MakeLinkedList(node*&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtLast(head,data);
        cin>>data;
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

// function  which takes istream object and node* object 
istream& operator >> (istream &is,node*&head){
    MakeLinkedList(head);
    return is;  // returning istream object for cascading 
}

// function which takes ostream object and node* object
ostream& operator << (ostream &os,node*head){
    print(head);
    return os;  // returning ostream object for cascading
}

int main() {
    node* head1=NULL;
    node* head2=NULL;

    cin>>head1>>head2;
    cout<<head1<<endl<<head2;
}
