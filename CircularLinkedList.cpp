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

void insertAtLast(node* &head,int data){
    if(head==NULL){
        node*n=new node(data);
        n->next=head;
        head=n;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node(data);
    }
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node* checkisPresent(node* &head,int data){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    node*notPresent=new node(-1);
    return notPresent;
}

int main() {
    node* head=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        node* cyclicNode=checkisPresent(head,data);
        if(cyclicNode->data!=-1){
            break;
        }
        insertAtLast(head,data);
        cin>>data;
    }
    print(head);
}
