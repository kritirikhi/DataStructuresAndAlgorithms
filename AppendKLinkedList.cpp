// in the linked list we have to append the last elements starting from kth element from last to  the front of the link list
// eg 2->6->3->4->5->NULL k=3  o/p 3->4->5->2->6->NULL
#include <iostream>
using namespace std;

// defining the node class having the data and next pointer
class node{
public:
    long long int data;
    node* next;

    node(long long int d){
        data=d;
        next=NULL;
    }
};

// function to insert the elements at the head
void insertAtHead(node* &head,long long int data){
    node* n=new node(data);
    n->next=head;
    head=n;
}

// function to insert node at last
void insertAtLast(node* &head,long long int d){
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

// function to print all the elements of the linked list
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void appendK(node* &head,long long int k,int n){
    //For k>=n
    k=k%n;
    //For k=n,2*n,... so on.
    if(k==0){
        return;
    }
    node*fast=head;
    node*slow=head;
    while(k>=1){
        fast=fast->next;
        k--;
    }
   
    node*sprev;
    node*fprev;
    
    while(fast!=NULL){
        fprev=fast;
        fast=fast->next;
        sprev=slow;
        slow=slow->next;
    }
    fprev->next=head;
    head=slow;
    sprev->next=NULL;
}

int main() {
    long long int n1;
    cin>>n1;
    node* head1=NULL;
    long long int data;
    for(long long int i=1;i<=n1;i++){
        cin>>data;
        insertAtLast(head1,data);
    }

    long long int k;
    cin>>k;

    appendK(head1,k,n1);
    print(head1);
}