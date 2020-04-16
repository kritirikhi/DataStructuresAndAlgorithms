#include <iostream>
#include<stack>
using namespace std;
int main() {
    stack<long long int> s;

    long long int n;
    cin>>n;
    long long int res[n];

    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin>>a[i];
        res[i]=-1;
    }    

    s.push(0);
    for(long long int i=1;i<n;i++){
        while(s.empty()==false && a[s.top()] < a[i]){
            res[s.top()]=a[i];
            s.pop();
        }
        s.push(i);
    }

    if(!s.empty()){
        for(long long int i=0;i<n;i++){
            while(s.empty()==false && a[s.top()] < a[i]){
                res[s.top()]=a[i];
                s.pop();
            }
            s.push(i);
        }
    }

     for(long long int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
}
