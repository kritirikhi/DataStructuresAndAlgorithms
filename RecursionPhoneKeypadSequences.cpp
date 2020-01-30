#include <iostream>
using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void keypadSequences(char input[],char output[],int i,int j){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<" , ";
        return;
    }

    int digit=input[i]-'0';
    // if input stirng has 1 or zero skip that
    if(digit==1 || digit==0){
        keypadSequences(input,output,i+1,j);
    }
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
}
