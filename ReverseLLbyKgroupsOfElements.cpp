// to reverse the LinkedList using k groups of elements
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
void MakeLinkedList(node*&head,int n){
    int data;
    cin>>data;
    while(n>0){
        insertAtLast(head,data);
        cin>>data;
        n--;
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

// function reverse the first k elements and recursively do for the other k elements till we reach end
// also returns the head node for each subList of k elements
node* reverse(node* head,int k){
    node*c=head;
    node*n=NULL;
    node*p=NULL;
    int count=0;

    while(c!=NULL && count<k){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        count++;
    }

    if(n!=NULL){
        head->next=reverse(n,k);
    }

    return p;


}
int main() {
    int n,k;
    cin>>n>>k;

    node* head1=NULL;
    MakeLinkedList(head1,n);
   
    node* reverseHead=reverse(head1,k);
    print(reverseHead);
}
