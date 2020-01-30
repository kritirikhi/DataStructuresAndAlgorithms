#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	for(int x=0;x<t;x++){
		string s;
		cin>>s;
		int n=s.length();
		for(int i=0;i<n-1;i++){       
			if(s.substr(i,2)=="pi"){
				cout<<"3.14";
				i++;
			}
			else{
				cout<<s[i];
			}
		}
        cout<<s[n-1];
        cout<<endl;

	}
	return 0;
}