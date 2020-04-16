#include<iostream>
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

void insertAtHead(node*&head,int data){
    node* n=new node(data);
    n->next=head;
    head=n;
}

// function to insert node at last
void insertAtLast(node* &head,long long int d){
    if(head==NULL){
		node* n=new node(d);
    	n->next=head;
    	head=n;
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

void sort(node* &sortHead,node* &head){
    node*c=head;
    while(c!=NULL){
        if(sortHead==NULL){
            insertAtHead(sortHead,c->data);
        }
        else{
            node*temp=sortHead;
            node*prev=sortHead;
            while(temp->next!=NULL && temp->data<=c->data){
                prev=temp;
                temp=temp->next;
            }

            if(temp->next==NULL && temp->data<c->data){
                insertAtLast(sortHead,c->data);
            }
            else if(prev==temp){
                insertAtHead(sortHead,c->data);
            }
            else{
                node *n=new node(c->data);
                n->next=prev->next;
                prev->next=n;
            }
        }
        c=c->next;
    }
    head=sortHead;
}

int main() {
	int n;
	cin>>n;
	node* head=NULL;
	int data;
	for(int i=0;i<n;i++){
		cin>>data;
		insertAtLast(head,data);
	}

    node* sortHead=NULL;
    sort(sortHead,head);
    print(head);
	return 0;
}