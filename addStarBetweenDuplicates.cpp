#include<iostream>
using namespace std;

void charFormat(char input[],int i,char output[],int j){
    // base case
    if(input[i]=='\0'){
        output[j]=='\0';
        cout<<output<<endl;
        return;
    }
    // recursive case
    if(input[i]!=input[i+1]){
        output[j]=input[i];
        charFormat(input,i+1,output,j+1);
    }
    else{
        output[j]=input[i];
        output[j+1]='*';
        charFormat(input,i+1,output,j+2);
    }
}

int main() {
    char input[1000];
    cin>>input;

    char output[1000];

    charFormat(input,0,output,0);
	return 0;
}