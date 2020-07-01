//                                                                  PALINDROMIC PAIRS

// Given a list of unique words A, find all pairs of distinct indices (i,j) in the given list such that concatenation of the two words, i.e. A[i] + A[j] is a palindrome.
// Note: A string is a palindrome if it reads the same backward as forward.

// Input 1:
//     A = ["abcd", "dcba", "lls", "s", "sssll"]
// Output 1:
//     [ [0,1], [1,0], [3,2], [2,4] ] 

// Input 2:
//     A = ["abc", "sa", "xy", "as" ]
// Output 2:
//     [ [1,3], [3,1] ]


#include<bits/stdc++.h>
using namespace std;


// to check whether the string s is palindrome or not
bool ispalin(string word){
    if(word.length()==1 || word.empty()){
        return true;
    }
    int l=0;
    int r=word.length()-1;
    while(l<=r){
        if(word[l]!=word[r]){
            return false;
        }
        l++;
        r--;
    }

    return true;
}   


// function to find the pairs which concatenate to form palindromic 
vector<vector<int>> solve(vector<string> &words) {
    vector<vector<int>> output;
    if(words.size()==0 || words.size()==1){
        return output;
    }

    // put all the strings with their indices in the map
    unordered_map<string,int> mp;
    for(int i=0;i<words.size();i++){
        mp[words[i]]=i;
    }

    // iterate over all the words
    for(int i=0;i<words.size();i++){
        
        // if the word is empty then we simply pair it will all the words present in the array except the word itself
        if(words[i].empty()){
            for(auto x:mp){
                
                if(x.second==i){
                    continue;
                }
                if(ispalin(x.first)){
                    output.push_back({x.second,i});   
                }
            }
            continue;
        }
    
        // otherwise
        //  make 2 substrings s1,s2
        // s1 will be the substring starting from 0th index till last index of the string
        // s2 will be the remaining string

        // 2 cases are possible
        // case 1 (ith index string)
        //  if s1 is a plaindromic string
        //  if reverse of s2 is present in the vector of strings
        //  then we get a pair (index of reverse of s2 in vector of strings , ith index)

        // case 2 (ith index string)
        //  if s2 is a plaindromic string
        //  if reverse of s1 is present in the vector of strings
        //  then we get a pair (ith index + index of reverse of s1 in vector of strings)
        for(int j=0;j<words[i].length();j++){
            string s1 = words[i].substr(0,j+1);
            string s2 = words[i].substr(j+1);
            
            // case 1
            if(ispalin(s1)){
                string temp=s2;
                reverse(s2.begin(),s2.end());
                if(mp.count(s2)==1 && mp[s2]!=i){
                    vector<int> temp;
                    temp.push_back( mp[s2]);
                    temp.push_back(i);
                    output.push_back( temp );
                }

                s2=temp;
            }

            // case 2
            if(ispalin(s2)){
                string temp=s1;
                reverse(s1.begin(),s1.end());
                if(mp.count(s1)==1 && mp[s1]!=i){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(mp[s1]);
                    output.push_back( temp );
                }
                s1=temp;
            }
        }

    }

    return output;
}

int main() {

    vector<string> words;
    words.push_back("abcd");
    words.push_back("dcba");
    words.push_back("lls");
    words.push_back("s");
    words.push_back("sssll"); 
  
    vector<vector<int>> result = solve(words);

    for(auto x:result){
        cout<<x[0]<<" "<<x[1]<<endl;
    }

    return 0;
}
