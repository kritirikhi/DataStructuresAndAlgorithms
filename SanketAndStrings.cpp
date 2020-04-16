#include <iostream>
#include<cstring>
using namespace std;

int findLen(string s,int k,char ch){
    int left=0,right=0;
    int count=0;
    int maxlenSubstring=1;

    while(right < s.length()){

        if(s[right]!=ch){
            count++;
        }    
        
        while(count>k){
            if(s[left]!=ch){
                count--;
            }
            left++;
        }

        maxlenSubstring=max(maxlenSubstring,right-left+1);
        right++; 
    }
    return maxlenSubstring;
}

int main() {
    string s;
    cin>>s;

    int k;
    cin>>k;

   int maxPerfectSubstring=max( findLen(s,k,'a'),findLen(s,k,'b') );
   cout<<maxPerfectSubstring<<endl;
}
