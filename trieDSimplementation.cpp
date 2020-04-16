// IMPLEMENTATION OF TRIE DATA STRUCTURE
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// Approach
// make a preifx tree (generic) where each node consists of:-
//      a character ch 
//      a small hashmap of type <char,node*> in which if the character is present in the current node then it will point to the next node containing the next character
//      a boolean variable which will be true when the terminal character occurs else false

// insertion operation in trie
//      add characters of the particular word one by one
//      make boolean value of the last character node as false

// similarly the find func works 


// node class
class node{
public:
    char data;
    unordered_map<char,node*> mp;
    bool terminal;
    node(char d){
        data=d;
        terminal=false;
    }
};

// class trie performing the functions of the trie data structure
class trie{
    node* root;
    int cnt;

    public:
    trie(){
        root=new node('\0');
        cnt=0;
    }

    // insertion operation
    void insert(char *w){

        node* temp=root;
        for(int i=0;w[i]!='\0';i++){
            char ch=w[i];
            if(temp->mp.count(ch)){
                temp=temp->mp[ch];
            }
            else{
                node* n= new node(ch);
                temp->mp[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }

    // search operation
    bool find(char *w){

        node* temp=root;
        for(int i=0;w[i]!='\0';i++){
            char ch=w[i];
            if(temp->mp.count(ch)==0){
                return false;
            }
            else{
                temp=temp->mp[ch];
            }
        }

        return temp->terminal;
    }
};

// MAIN
int main() {
    trie t;
    char words[][10]={{"dadu"},{"dadi"},{"kriti"},{"amersha"},{"mom"},{"dad"}};
    for(int i=0;i<6;i++){
        t.insert(words[i]);
    }

    char word[1000];
    cin>>word;
    if(t.find(word)){
        cout<<word<<" is present";
    }
    else{
        cout<<word<<" is not present";
    }
}
