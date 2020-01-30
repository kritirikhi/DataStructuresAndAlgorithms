// searching an element in a linked list both recursively and iteratively
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

// function to print all the elements of the linked list
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"  ";
        head=head->next;
    }
    cout<<endl;
}


// to search the number recursively in linked list
bool searchRecursively(node* head,int key){
    // base case
    if(head==NULL){
        return false;
    }

    // rec case
    if(head->data==key){
        return true;
    }
    searchRecursively(head->next,key);
}

// to search the number using loops
bool searchIterative(node* head,int key){
    while(head!=NULL){
        if(head->data==key){
            return true;
        }
        head=head->next;
    }
    return false;
}

int main() {
    node* head=NULL;
    insertAtHead(head,12);
    insertAtHead(head,3);
    insertAtHead(head,16);
    insertAtHead(head,5);
    insertAtHead(head,19);

    if(searchRecursively(head,11)){
        cout<<"number is present"<<endl;
    }
    else{
        cout<<"number is not present"<<endl;
    }

    if(searchIterative(head,3)){
        cout<<"number is present"<<endl;
    }
    else{
        cout<<"number is not present"<<endl;
    }

}
