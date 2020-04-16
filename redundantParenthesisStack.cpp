#include <iostream>
#include<cstring>
#include<stack>
using namespace std;

bool checkRedundant(char a[]){
    stack<int> s;
    for(int i=0;i<strlen(a);i++){
        
        if(a[i]==')'){
            int top=s.top();
            s.pop();
            if(top=='('){
                return true;  // duplication
            }
            while(top!='('){
                top=s.top();
                s.pop();
            }
        }

        else{
            s.push(a[i]);
        }
    }
    return false; //  no duplication
}

int main() {
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
        char a[105];
        cin>>a;
        if(checkRedundant(a)){
            cout<<"Duplicate"<<endl;
        }
        else{
            cout<<"Not Duplicates"<<endl;
        }
        
    }
}
