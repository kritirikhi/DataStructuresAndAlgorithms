#include<iostream>
#include<cstring>
using namespace std;

string replacePi(char s[],int i){
    if(s[i]=='\0'){
        return s;
    }

    string res=replacePi(s,i+1);
    if(s[i]=='p' && s[i+1]=='i'){
        res=res.substr(0,i)+"3.14"+res.substr(i+2);
    }
    return res;
}

int main() {
    int t;
    cin>>t;

    for(int x=0;x<t;x++){
        char s[1000];
        cin>>s;
        cout<<replacePi(s,0)<<endl;
    }
	return 0;
}