// You are given a string S consisting of lowercase alphabets. A good subsequence of this string is a subsequence which contains distinct characters only. 
// Determine the number of good subsequences of the maximum possible length modulo 1000000007 .

// In other words, determine the length X of the longest good subsequence and the number of good subsequences of length X modulo 1000000007 .

// Input format

// First line: An integer T denoting the number of test cases
// Each of the next t lines: String 

// Output format
// For each test case, print the number of good subsequences of the maximum length modulo 1000000007 .
// Answer for each test case should come in a new line.

// INPUT
// 3
// aaa
// abba
// abcd

// OUTPUT
// 3
// 4
// 1

// Explanation
// In the first testcase, any one of the a can be chosen. Hence there are 3 good subsequences of maximum length.

// In the second testcase, the maximum length of a good subsequence is 2 . There are 4 such subsequences (listed by indices):
// (1, 2)
// (1, 3)
// (2, 4)
// (3, 4)

// In the third testcase, the maximum length of a good subsequence is 4 and there is only 1 such subsequence


include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    for(int x=0;x<t;x++){
        char a[200000];
        cin>>a;

        int freq[26]={0};

        for(int i=0;a[i]!='\0';i++){
            int ch=a[i];
            freq[ch-'a']++;
        }
        
        long long int ans=1;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                ans=ans*freq[i]; 
                ans=ans%1000000007;
            }
        }
        
        cout<<ans<<endl;
    
    }

    return 0;
    
}