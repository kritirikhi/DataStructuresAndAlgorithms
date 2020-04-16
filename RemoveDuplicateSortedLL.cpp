#include<iostream>
using namespace std;

class node{
public:
	node* next;
	long long int data;
	node(long long int d){
		data=d;
		next=NULL;
	}

};

void insert(node* &head,long long int data){
	if(head==NULL){
		node* n= new node(data);
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

void removeDuplicate(node* &head){
    node* temp=head;
    node* prev=head;
    while(temp->next!=NULL){
        if(temp->next->data==temp->data){
            node* p=temp;
            node* t=temp->next;
            p->next=t->next;
            delete t;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
	long long int t;
	cin>>t;

	for(long long int x=0;x<t;x++){
		long long int n;
		cin>>n;

		node* head=NULL;
		long long int data;
		while(n>0){
			cin>>data;
			insert(head,data);
			n--;
		}
        removeDuplicate(head);
        print(head);
	}
	return 0;
}