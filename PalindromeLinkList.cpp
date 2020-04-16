// check if a linked list is a palindrome or not
#include <iostream>
using namespace std;

// creation of a class containing data and the next pointer
class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }

};

// function which adds node to the tail of the linked list
// but if head==NULL then the function adds the node to the head of the linked list
void insertAtTail(node* &head,int data){
    if(head==NULL){
        node* n=new node(data);
        n->next=head;
        head=n;
    }
    else{
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node(data);
    }
}

// function to reverse the linked list
void reverse(node *&head){
    node*c=head;
    node*p=NULL;
    node* n;
    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}

// function which checks whether the linked list is palindrome or not
bool checkPalin(node* head,node* head2){
    while(head!=NULL){
        if(head->data!=head2->data){
            return false;
        }
        head=head->next;
        head2=head2->next;
    }
    return true;
}

int main() {
    node* head=NULL;
    node* head2=NULL;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,data);
        insertAtTail(head2,data);

    }

    reverse(head2);

    if(checkPalin(head,head2)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}
