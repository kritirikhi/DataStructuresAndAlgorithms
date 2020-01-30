#include <iostream>
using namespace std;

void permutation(char input[],int i){
    // base case
    if(input[i]=='\0'){
        cout<<input<<" , ";
        return;
    }

    // recursive case
    for(int j=i;input[j]!='\0';j++){
        swap(input[j],input[i]);
        permutation(input,i+1);

        // backtrack -- restore the array
        swap(input[j],input[i]);
    }
}

int main() {
    char input[100];
    cin>>input;

    char output[100];
    permutation(input,0,output,0);
}
