#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    
    for(int q=0;q<t;q++){
        string s;
        cin>>s;
        
        stack<string> stack1;
        int i=s.length()-1;
        while(i>=0){
            if(s[i]=='('){
                i--;
                int num=s[i]-'0';
                string temp="";
                while(stack1.top()!= ")" && !stack1.empty()){
                    temp=temp+stack1.top();
                    stack1.pop();
                }

                if(stack1.top()==")"){
                    stack1.pop();
                }
                
                
                string temp2="";
                for(int i=1;i<=num;i++){
                    temp2+=temp;
                }
                
                stack1.push(temp2);
            }
            
            else{
                string s2="";
                s2=s2+s[i];
                stack1.push(s2);
            }
            i--;
        }
        
        s="";
        while(!stack1.empty()){
            s+=stack1.top();
            stack1.pop();
        }
        
        long long int x=1;long long int y=1;
        for(long long int i=0;i<s.length();i++){
            if(s[i]=='N'){
                if(y==1){
                    y=1000000000;
                }
                else{
                    y--;
                }
            }
            
            else if(s[i]=='S'){
                if(y==1000000000){
                    y=1;
                }
                else{
                    y++;   
                }
            }
            
            else if(s[i]=='E'){
                if(x==1000000000){
                    x=1;
                }
                else{
                    x++;
                }
            }
            
            else if(s[i]=='W'){
                if(x==1){
                    x=1000000000;
                }
                else{
                    x--;   
                }
            }
        }
        
        cout<<"Case #"<<q+1<<": "<<x<<" "<<y<<endl;
    }

	return 0;
}
