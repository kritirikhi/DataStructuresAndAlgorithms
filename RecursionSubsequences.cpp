#include <iostream>
using namespace std;

void subsequences(char input[],char output[],int i,int j){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<" , ";
        return;
    }

    //  when character is to be included
    output[j]=input[i];
    subsequences(input,output,i+1,j+1);
    // when character is not to be included
    subsequences(input,output,i+1,j);
}

int main() {
    char input[100];
    cin>>input;

    char output[100];
    subsequences(input,output,0,0);
}
