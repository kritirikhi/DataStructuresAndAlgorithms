#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
    int n;
    cin>>n;

    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[j]+s[i]>s[i]+s[j]){
                string temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<endl;
    }
}