// making even nos to be displayed after odd nos in linked list
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
    while(n>=1){
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

// function makes 2 linked lists having only odd nos and even nos respectively
// at last merge the two lists
void evenOdd(node* &head,node* &even,node* &odd){
    while(head!=NULL){
        if( (head->data)%2!=0 ){
            insertAtLast(odd,head->data);
        }
        else{
            insertAtLast(even,head->data);
        }
        head=head->next;
    }
    node*temp=odd;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=even;
}

int main() {
    int n;
    cin>>n;
    
    node* head=NULL;
    MakeLinkedList(head,n);

    node*even=NULL;
    node*odd=NULL;

    evenOdd(head,even,odd);
    print(odd);
}
