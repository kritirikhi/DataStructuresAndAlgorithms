//                                                                          MAPPED STRINGS PROBLEM

// We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. Given a number, you have to print all the possible strings.

// Input Format
// A single line contains a number.

// Constraints
// Number is less than 10^6

// Output Format
// Print all the possible strings in sorted order in different lines.

// Sample Input
// 123
// Sample Output
// ABC
// AW
// LC
// Explanation
// '1' '2' '3' = ABC
// '1' '23' = AW
// '12' '3' = LC


//Approach

// We can solve the problem using recursion
// for a ith index in the input string we have two options:- 
//     1) take the ith character and convert into that alphabet. Include it into the output string and 
//       call the function by incrementing the input index as well as output index 
//     2) take the first 2 characters (i,i+1)th and convert them to number. If number is <=26 then convert the number into the alphabet and 
//       call the function by incrementing the input index by 2 and output index by 1

#include <iostream>
using namespace std;

void mapped(char input[],char output[],int inIdx,int outIdx){
    if(input[inIdx]=='\0'){
        output[outIdx]='\0';
        cout<<output<<endl;
        return;
    }
    
    int digit = input[inIdx]-'0';
    char ch = digit+'A'-1;
    output[outIdx]=ch;
    mapped(input,output,inIdx+1,outIdx+1);
    
    if(input[inIdx+1]!='\0'){
        int digit2=input[inIdx+1]-'0';
        int num = digit*10 + digit2;
        if(num<=26){
            char ch = num + 'A' -1;
            output[outIdx]=ch;
            mapped(input,output,inIdx+2,outIdx+1);
        }
    }
}

int main() {
    
    char input[1000000];
    cin>>input;
    char output[1000000];
    
    mapped(input,output,0,0);
	return 0;
}
