#include <iostream>
#include<stack>
using namespace std;
int main() {
    long long int q;
    cin>>q;
    stack<long long int> s;
    for(long long int x=0;x<q;x++){
        long long int type,c;
        cin>>type;
        if(type==2){
            cin>>c;
            s.push(c);
        }
        else{
            if(!s.empty()){
                cout<<s.top()<<endl;
                s.pop();
            }
            else{
                cout<<"No Code"<<endl;
            }
        }

    }
}
