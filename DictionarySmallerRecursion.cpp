#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;

void dictionarySmaller(char input[],int i){
    // base case
    if(input[i]=='\0'){
        v.push_back(input);
        return;
    }

    // rec case
    for(int j=i;input[j]!='\0';j++){
        swap(input[j],input[i]);
        dictionarySmaller(input,i+1);
        swap(input[j],input[i]);
    }
}

int main() {
    char input[26];
    cin>>input;

    string temp=input; 
    int i=0;
    dictionarySmaller(input,i);

     sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        if(v[i]<temp){
            cout<<v[i]<<endl;
        }
    }
	return 0;
}