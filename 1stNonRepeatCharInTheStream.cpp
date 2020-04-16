// to find the first occurence of the character till a particular entry by the user
#include <iostream>
#include <queue>
#include<unordered_map>
using namespace std;

// make use of hash map , queue
// when a character is entered by the user, first push it in queue and increment its count
// then iterate over the queue, if count of q.front() > 1 then pop it otherwise print it and break the loop
// if the queue gets empty at the end then cout -1 as there is no more element which occurs more than once
int main() {
    unordered_map<char,int> mp;
    queue<char> q;

    char ch;
    cin>>ch;
    while(ch!='.'){
        q.push(ch);
        mp[ch]++;

        while(!q.empty()){
            if(mp[q.front()] > 1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty()){
            cout<<"-1";
        }
        cin>>ch;
    }
}
