// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
#include <iostream>
#include<cstring>
using namespace std;

// fucntion checking the string input by the user
bool checkParenthesis(char a[],int n,int i,int roundOpen,int roundClose,int squareOpen,int squareClose,int curlOpen,int curlClose){
    // base case
    if(i==n){
        if(roundOpen==roundClose && squareOpen==squareClose && curlOpen==curlClose){
            return true;
        }
        return false;
    }

    // checks
    // 1) the first character of the input string can't be the closing bracket.
    // 2) if the opening bracket (,[,{ occurs then increment the count of that bracket and check for the next bracket in the array.
    // 3) if the closing bracket for eg ')' occurs:----
    //                         ============
    //      a)  if the count of opening bracket > count of closing bracket and the one bracket prev to closing bracket is either (,),],} then the expression is valid till
    //          till there and we can increment the count of closing bracket and check for the next bracket in the array.  
    //      b)  else return false as expression is not valid.

    if(a[0]==')' || a[0]==']' || a[0]=='}'){
        return false;
    }
    if(a[i]=='('){
        roundOpen++;
        checkParenthesis(a,n,i+1,roundOpen,roundClose,squareOpen,squareClose,curlOpen,curlClose);
    }
    else if(a[i]=='['){
        squareOpen++;
        checkParenthesis(a,n,i+1,roundOpen,roundClose,squareOpen,squareClose,curlOpen,curlClose);
    }
    else if(a[i]=='{'){
        curlOpen++;
        checkParenthesis(a,n,i+1,roundOpen,roundClose,squareOpen,squareClose,curlOpen,curlClose);
    }



    else if(a[i]==')' && roundOpen>roundClose && (a[i-1]=='(' || a[i-1]==']' || a[i-1]=='}' || a[i-1]==')') ){
        roundClose++;
        checkParenthesis(a,n,i+1,roundOpen,roundClose,squareOpen,squareClose,curlOpen,curlClose);
    }
    else if(a[i]==']' && squareOpen>squareClose && (a[i-1]=='[' || a[i-1]==')' || a[i-1]=='}' || a[i-1]==']') ){
        squareClose++;
        checkParenthesis(a,n,i+1,roundOpen,roundClose,squareOpen,squareClose,curlOpen,curlClose);
    }
    else if(a[i]=='}' && curlOpen>curlClose && (a[i-1]=='{' || a[i-1]==')' || a[i-1]==']' || a[i-1]=='}') ){
        curlClose++;
        checkParenthesis(a,n,i+1,roundOpen,roundClose,squareOpen,squareClose,curlOpen,curlClose);
    }


    // else if(a[i]==')' && roundOpen<=roundClose && (a[i-1]!='(' || a[i-1]!=']' || a[i-1]!='}' || a[i-1]!=')') ){
    //     return false;
    // }
    // else if(a[i]==']' && squareOpen<=squareClose && (a[i-1]!='[' || a[i-1]!=')' || a[i-1]!='}' || a[i-1]!=']') ){
    //     return false;
    // }
    // else if(a[i]=='}' && curlOpen<=curlClose && (a[i-1]!='{' || a[i-1]!=')' || a[i-1]!=']' || a[i-1]!='}') ){
    //     return false;
    // }

    else {
        return false;
    }
    
}
// driver code
int main() {
    // input the string in a character array
    char a[1000005];
    cin>>a;
    int n=strlen(a);

    // calling the function which will check whether the parenthesis are in correct order or not
    if( checkParenthesis(a,n,0,0,0,0,0,0,0) ){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
