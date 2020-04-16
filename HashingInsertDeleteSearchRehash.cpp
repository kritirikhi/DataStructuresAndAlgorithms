//                                                              HASHING (manually)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// makes the node for the hashtable
// the node consists of key,value,next pointer
class node{
public:
    node* next;
    string key;
    int value;
    node(string s,int v){
        key=s;
        value=v;
    }
    ~node(){
        if(next!=NULL){
            delete next;
        }
    }
};

// Hash Table class which actually makes the hashtable 
// includes operations:-
//  hashfunction
//  insertion,deletion,searching
//  rehashing
class hashtable{

    node** buckets; // pointer to the array of pointers
    int cs;         // current size of the hashtable
    int ts;         // max size of the hashtable
   
   // the function performs rehashing when necesaary
   //   rehashing is required when the size of the link list becomes large
   //   it is done by doubling the size of the table and adding all the elements in that table
    void rehash(){
        node** oldBuckets=buckets; // declaring old table as oldBuckets
        int oldts=ts;              // declaring old table size as oldts
        ts=ts*2;                   // changing new ts as twice of the prev table size
        cs=0;                      // making current size as 0

        buckets=new node* [ts];    // new table pointer

        for(int i=0;i<ts;i++){     // initializing all the nodes of the new table as NULL
            buckets[i]=NULL;
        }

        // adding old table values to the new table 
        // also deleting the old table side by side
        for(int i=0;i<oldts;i++){
            node* temp=oldBuckets[i];
            if(temp!=NULL){
                while(temp!=NULL){
                    insert(temp->key,temp->value);
                    temp=temp->next;
                }
                delete oldBuckets[i];
            }
        }
        delete [] oldBuckets;
    }

    // hash func take the string key and returns the integer value which is the index of the hashtable
    int hashFunction(string key){
        int p=1;
        int ans=0;
        int l=key.length();
        for(int i=0;i<l;i++){
            ans=ans + key[l-i-1]*p;
            p=p*37;
            p=p%ts;
            ans=ans%ts;
        }
        return ans;
    }

public:

    hashtable(int size=7){
        ts=size;
        cs=0;
        buckets=new node* [ts];

        for(int i=0;i<ts;i++){
            buckets[i]=NULL;
        }
    }

    // to insert the value:-
    //  calc the hashfunc
    //  insert the value at the index returned by the hash func
    //  if collision occurs then add the element to the head of the link list
    void insert(string key,int value){
        int i=hashFunction(key);

        node* n=new node(key,value);
        n->next=buckets[i];
        buckets[i]=n;
        cs++;

        float loadFactor=(float)cs/ts;

        if(loadFactor > .7){
            cout<<loadFactor<<endl;
            rehash();
        }
    }

    // printing all the entries of the hash table
    void printHashTable(){
        for(int i=0;i<ts;i++){
            cout<<"bucket "<<i<<" -> ";
            node* temp=buckets[i];
            while(temp!=NULL){
                cout<<temp->key<<",";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    // func to search the element with the particular key
    // return the value of the key
    int* search(string key){
        int i=hashFunction(key);
        node* temp=buckets[i];
        while(temp!=NULL){
            if(temp->key==key){
              return &(temp->value);
            }
            temp=temp->next;
        }   
        return NULL;
    }

    // deleting the node having the key given by the user as the parameter
    void erase(string key){
        if(search(key)!=NULL){
            int i=hashFunction(key);
            node* temp=buckets[i];
            node* prev=temp;
            while(temp!=NULL){
                if(temp->key==key){
                    node* deleteNode=temp;
                    prev->next=temp->next;
                    delete deleteNode;
                    break;
                }
                prev=temp;
                temp=temp->next;
            }
        }
        else {
            cout<<key<<" is not in hashtable"<<endl;
        }
    }
    
};

int main() {
    hashtable h;
    h.insert("Mango",100);
    h.insert("Apple",170);
    h.insert("Guava",140);
    h.insert("Banana",130);
    h.insert("Chiku",120);

    h.printHashTable();

    // string f;
    // cin>>f;

    // int* price=h.search(f);
    // if(price==NULL){
    //     cout<<f<<" is not present";
    // }
    // else{
    //     cout<<"price of "<<f<<" is "<<*price;
    // }

    // h.erase("kiku");
}

