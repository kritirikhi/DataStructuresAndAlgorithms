// Longest Palindromic Substring in a string
#include <iostream>
#include<cstring>
using namespace std;

bool ispalin(string temp,int s,int e){
    if(s==e){
        return true;
    }
    if(s>e){
        return true;
    }
    if(temp[s]!=temp[e]){
        return false;
    }
    if(temp[s]==temp[e]){
        bool dec=ispalin(temp,s+1,e-1);
        if(dec){
            return true;
        }
        return false;
    }
}

int main() {
    string s;
    cin>>s;

    string palinDromicString="";
    int maxLen=0;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            string temp=s.substr(i,j-i+1);
            if(ispalin(temp,0,j-i) && ((j-i+1) > 1) && ((j-i+1) > maxLen) ){
                maxLen=j-i+1;
                palinDromicString=temp;
            }
        }
    }

    cout<<"Longest Palindromic Substring is "<<palinDromicString<<" Length:- "<<maxLen;
}
