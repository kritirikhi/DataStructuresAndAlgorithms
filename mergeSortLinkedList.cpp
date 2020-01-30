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

node *midpoint(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* fast=head->next;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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


node* mergeSort(node* head){
    // base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    // rec case
    node* mid=midpoint(head);
    node*a=head;
    node*b=mid->next;
    mid->next=NULL;
    
    a=mergeSort(a);
    b=mergeSort(b);
    
    // merge the sorted lists
    node *c=merge(a,b);
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
    node* head=NULL;
    makeList(head);
    cout<<"original linked list"<<endl;
    print(head);
    
    node* sorted= mergeSort(head);
    cout<<"sorted list is"<<endl;
    print(sorted);
	return 0;
}
