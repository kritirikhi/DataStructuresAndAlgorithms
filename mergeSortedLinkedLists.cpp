#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insertAtHead(node*&head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}

void insertAtTail(node*&head,int data){
    if(head==NULL){
        insertAtHead(head,data);
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node(data);
    }
}

void makeList(node* &head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}

node *merge(node* a,node* b){
    // base case
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    
    // rec case 
    node *c;
    if(a->data<b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    node* head1=NULL;
    makeList(head1);
    cout<<"fist sorted linked list"<<endl;
    print(head1);
    
    node* head2=NULL;
    makeList(head2);
    cout<<"second sorted list"<<endl;
    print(head2);
    
    node* mergedList=merge(head1,head2);
    cout<<"merged lists"<<endl;
    print(mergedList);
	return 0;
}
