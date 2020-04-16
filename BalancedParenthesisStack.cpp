// we are given a string containing parenthesis or an expression eg (a+(b+c)) and we have to check whether the parenthesis are in correct order or not
#include <iostream>
#include<cstring>
#include<stack>
using namespace std;


// use stack for the problem as parenthesis follow last in first out rule
// the bracket open last is closed first
// iterate over the entire string s:-
//      if s[i]==( then push it in stack
//      else if s[i]==)
//          then if stack is empty or the s.top==) then expression is not valid and return false
// when the iteration is over
//      if stack is empty return true 
//      else return false as stack still contain elements and the expression is not

bool checkExpression(string s){
    stack<char> parenthesis;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]=='('){
            parenthesis.push(s[i]);
        }
        else if(s[i]==')'){
            if(parenthesis.empty() || parenthesis.top()==')'){
                return false;
            }
            parenthesis.pop();
        }
    }
    if(parenthesis.empty()){
        return true;
    } 
    else{
        return false;
    }
}

int main() {
    string s;
    cin>>s;

    if(checkExpression(s)){
        cout<<"Expression Valid";
    }
    else{
        cout<<"Expression Not Valid";
    }

}
