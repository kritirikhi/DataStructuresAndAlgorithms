#include<iostream>
using namespace std;

void removeDuplicate(char input[],int i,char output[],int j){
    // base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output;
        return;
    }

    // recursive case
    if(input[i]==input[i+1]){
        output[j]=input[i];
        removeDuplicate(input,i+2,output,j+1);
    }
    else{
        output[j]=input[i];
        removeDuplicate(input,i+1,output,j+1);
    }
}

int main() {
    char input[1000];
    cin>>input;

    char output[1000];
    removeDuplicate(input,0,output,0);
	return 0;
}