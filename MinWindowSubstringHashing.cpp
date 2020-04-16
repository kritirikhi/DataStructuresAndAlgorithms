// given a string s. we have to find min window which includes atleast the characters of the pattern string.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string calcMinWindow(string s,string pat){
    int len1=s.length();
    int len2=pat.length();

    if(len1<len2){
        string temp="No Window Found";
        return temp;
    }
    int hash_s[256]={0};
    
    int hash_pat[256]={0};
    for(int i=0;i<len2;i++){
        hash_pat[pat[i]]+=1;
    }

    int start=0,start_index=-1,minLen=INT_MAX,count=0;
    int j=0;
    for(;j<len1;j++){
        hash_s[s[j]]+=1;
        if(hash_pat[s[j]]!=0 && hash_s[s[j]]<=hash_pat[s[j]] ){
            count++;
        }

        if(count==len2){
            while(hash_s[s[start]]>hash_pat[s[start]] || hash_pat[s[start]]==0  ){
                if(hash_s[s[start]]>hash_pat[s[start]]){
                    hash_s[s[start]]-=1;   
                }
                start=start+1;
            }
            int len=j-start+1;
            if(minLen>len){
                minLen=len;
                start_index=start;
            }
        }
    }
    if(start_index==-1){
        string temp1="No Window Found";
        return temp1;
    }

    string temp3=s.substr(start_index,minLen);
    return temp3;

}

int main() {
    string s;
    string pat;
    cin>>s>>pat;

    cout<<calcMinWindow(s,pat);
}
