#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
public:
    char data;
    unordered_map<char,node*> mp;
    bool terminal;
    int count;
    node(char d){
        data=d;
        count=1;
        terminal=false;
    }
};

class trie{
    node* root;

    public:
    trie(){
        root=new node('\0');
    }

    void insert(char *a){
        node* temp=root;
        for(int i=0;a[i]!='\0';i++){
            char ch=a[i];
            if(temp->mp.count(ch)){
                temp=temp->mp[ch];
                temp->count++;
            }
            else{
                node* n=new node(ch);
                temp->mp[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }

    void addMatch(node* root,vector<string> &ans,string s){
        if(root->mp.size()==0){
            ans.push_back(s);
            return;
        }
        if(root->terminal==true){
            ans.push_back(s);
        }

        for(auto i:root->mp){
            string x= s+i.first;
            addMatch(i.second,ans,x);
        }
    }

    vector<string> string_match(char *pat){
        node* temp=root;
        for(int i=0;pat[i]!='\0';i++){
            char ch=pat[i];
            if(temp->mp.count(ch)==0){
                insert(pat);
                return vector<string>();
            }
            temp=temp->mp[ch];
        }

        vector <string> ans;
        addMatch(temp,ans,string(pat));
        return ans;
    }

};

int main() {
    trie t;

    int n;
    cin>>n;

    for(int x=0;x<n;x++){
        char a[200005];
        cin>>a;
        t.insert(a);
    }

    int q;
    cin>>q;
    for(int y=0;y<q;y++){
        char a[1000];
        cin>>a;
        vector<string> result=t.string_match(a);
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<endl;
        }
        if(result.size()==0){
            cout<<"No suggestions"<<endl;
        } 
    }


}
