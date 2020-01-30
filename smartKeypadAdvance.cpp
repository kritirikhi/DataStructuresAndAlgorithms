#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

char keypad[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
string searchIn [11] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
};

vector <string> v;

void keypadSequences(char input[],char output[],int i,int j){
	// base case
	if(input[i]=='\0'){
		output[i]='\0';
		v.push_back(output);
		return;
	}
	// rec case
	int digit=input[i]-'0';
	for(int k=0;keypad[digit][k]!='\0';k++){
		output[j]=keypad[digit][k];
		keypadSequences(input,output,i+1,j+1);
	}
}

int main() {

	char input[100];
	cin>>input;

	char output[100];
	keypadSequences(input,output,0,0);
  
    for(int i=10;i>=0;i--){
        string s1=searchIn[i];
        for(int j=0;j<v.size();j++){
            string s2=v[j];
            for(int k=0;k<s1.size()-s2.size()+1;k++){
                if(s1.substr(k,s2.size())==s2){
                    cout<<s1<<endl;
                }
            }
        }
    }
   
	return 0;
}