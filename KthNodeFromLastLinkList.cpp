#include <iostream>
using namespace std;

// creation of class node which includes data and the next pointer
class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

// function to insert at head of the linked list
void insertAtHead(node*&head,int data){
    node*n=new node(data);
    n->next=head;
    head=n;
}

// func to print all the elements of the linked list
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
}

// the func returns the kth node from end
// a kind of runner technique is used
// the fast ans slow pointers are initialised to head
// the fast pointer move k steps first
// then fast and slow pointers are moved simultaneously by 1 step each till fast!=null and the final position of flow pointer will be the kth node from last
// basically, fast first move k steps and then remaining n-k steps are to be moved from head
// so the slow pointer takes n-k steps till fast reaches NULL
// 
node* findkthNode(node* head,int k){
    node* fast=head;
    node* slow=head;
    while(k>0){
        fast=fast->next;
        k-=1;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

int main() {
    node* head=NULL;
    insertAtHead(head,12);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,10);
    insertAtHead(head,18);
    insertAtHead(head,20);

    cout<<"original linked list"<<endl;
    print(head);

    int k;
    cin>>k;
    node *kthNode = findkthNode(head,k);
    cout<<k<<" node from end is "<<kthNode->data<<endl;
}
