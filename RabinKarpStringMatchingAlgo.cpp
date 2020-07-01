//                                                                  RABIN KARP STRING MATCHING ALGORITHM

// Return the index of the first occurrence of pattern in string, or -1 if pattern is not part of string.
// Eg:- string => abbcde
//      pat => bcd 
//      output => 2 (pattern bcd starts at index 2 in given string)


// Approach 

// this algorithm uses rolling hash for the matching 
// ROLLLING HASH :- 
//     let the string be  abcda 
//     the hash func of abc be sum of ASCII values of the substring abc 
//     hash(abc)=97+98+99 
//     now hash of rest of the substrings of same length can be calculated in O(1) time 
//     hash(bcd) = hash(abc) - ASCII(a) + ASCII(d) 
//     similarly the hash of rest of the substrings can be calculated in O(1) time 
    
    
// ALGORITHM

// calculate the hash func of the substring of length == pattern.length 
// calculate the hash func of the pattern
// iterate over all the string :- 
//     if hash(substring)==hash(pat)  
//         check iteratively whether the substring and the pattern are same or not 
//         if not iterate the string from next index 
//     else 
//         change the hashfunc according to the next coming substring 


#include <bits/stdc++.h>
using namespace std;

// func to check whether the 2 strings (substring,pattern) are same or not
bool isequal(string s,string p,int start1,int end1,int start2,int end2){
    if( (end1-start1)!=(end2-start2) ){
        return false;
    }
    
    while(start1<=end1 && start2<=end2){
        if(s[start1]!=p[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    
    return true;
}

int main() {
    int p=13;
	string s;
	cin>>s;
	
	string pat;
	cin>>pat;
	
	int strhash=0;
	int pathash=0;
	
	// calculating the hashfunc of the string and the pattern
// 	hash(abc) = a*(prime^0) + b*(prime^1) + c*(prime^2)
	for(int i=0;i<pat.length();i++){
	    strhash+=s[i]*pow(p,i);
	    pathash+=pat[i]*pow(p,i);
	}
	
	// iterating over the whole string 
	for(int i=0;i<=s.length()-pat.length();i++){
	    if(strhash==pathash  &&  isequal(s,pat,i,i+pat.length()-1,0,pat.length()-1) ){
	        cout<<i<<endl;
	    }
	    // rehashing (changing the hashfunc acc to the next substring)
	    if(i<s.length()-pat.length()){
	        strhash=strhash-s[i];
	        strhash/=p;
	        strhash+=s[i+pat.length()]*pow(p,pat.length()-1);
	    }
	}
	return 0;
}
