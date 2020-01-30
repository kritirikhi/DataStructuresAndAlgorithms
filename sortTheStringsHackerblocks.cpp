#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string getKey(string str,int key){
    // char *p=strtok((char*)str.c_str()," ");
    char *p=strtok((char*)str.c_str()," ");
    while(key>1){
        p=strtok(NULL," ");
        key--;
    }
    return (string)p;
}

int convertToInt(string s){
    int ans=0;
    int power=1;
    for(int i=s.length()-1;i>=0;i--){
        ans += (s[i]-'0')*power;
        power=power*10;
    }
    return ans;
}

bool compareNumeric(pair<string,string> s1, pair<string,string> s2){
    int num1=convertToInt(s1.second);
    int num2=convertToInt(s2.second);
    return num1<num2;
}

bool compareLexico(pair<string,string> s1, pair<string,string> s2){
    return s1.second<s2.second;
}

int main() {

    int n;
    cin>>n;
    cin.get();

    string a[1000];
    for(int i=0;i<n;i++){
        getline(cin,a[i]);
    }

    int key;
    string reverse,compareType;
    cin>>key>>reverse>>compareType;

    // making a pair of strings which consists of the string plus the token acc to key  eg:- if key=3 then pair is ("20 30 40"  40)
    pair<string,string> pair[1000];
    for(int i=0;i<n;i++){
        pair[i].first=a[i];
        pair[i].second=getKey(a[i],key);
    }

    // sort acc to compare type
    if(compareType=="numeric"){
        sort(pair,pair+n,compareNumeric);
    }
    else{
        sort(pair,pair+n,compareLexico);
    }

    // if reverse is true
    if(reverse=="true"){
        for(int i=0;i<n/2;i++){
            swap(pair[i],pair[n-i-1]);
        }
    }

    // printing
    for(int i=0;i<n;i++){
        cout<<pair[i].first<<endl;
    }
}
