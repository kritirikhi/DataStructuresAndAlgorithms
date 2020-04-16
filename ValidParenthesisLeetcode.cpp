//                                              Leetcode question (Valid Parenthesis)
// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. 
// We define the validity of a string by these rules:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.

// Example 1:
// Input: "()"
// Output: True

// Example 2:
// Input: "(*)"
// Output: True

// Example 3:
// Input: "(*))"
// Output: True


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool checkValidString(string s) {
    
    stack<char> stack1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='*'){
            stack1.push(s[i]);
        }
        
        else if(s[i]==')'){
            if(stack1.empty()){
                return false;
            }
            
            if(stack1.top()=='('){
                stack1.pop();
                continue;
            }
            
            int countStar=0;
            int flag=0;
            while(1){
                if(stack1.empty()){
                    break;
                }
                if(stack1.top()=='*'){
                    countStar++;
                    stack1.pop();
                }
                else if(stack1.top()=='('){
                    stack1.pop();
                    flag=1;
                    break;
                }
            }
            
            if(flag==0){
                countStar--;
                while(countStar>0){
                    stack1.push('*');
                    countStar--;
                }
            }
            else{
                while(countStar>0){
                    stack1.push('*');
                    countStar--;
                }
            }
        }
    }
    
    if(stack1.empty()){
        return true;
    }
    
    stack<char> stack2;
    while(!stack1.empty()){
        if(stack1.top()=='*'){
            stack2.push(stack1.top());
            stack1.pop();
        }
        else if(stack1.top()=='('){
            if(stack2.empty()){
                return false;
            }
            
            else{
                stack2.pop();
                stack1.pop();
            }
        }
    }

    return true;
}


int main() {
    string s;
    cin>>s;
    
    if(checkValidString(s)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
	return 0;
}
