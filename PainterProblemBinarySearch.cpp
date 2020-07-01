//                                                                    PAINTER'S PROBLEM


// You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. 
// There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. 
// You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board. Return the ans % 10000003

// Input Format
// First line contains three space seperated integers N,K and T ,where
// N = Size of array,
// K = No of painters available ,
// T = Time taken to print each board by one painter
// Next line contains N space seperated positive integers denoting size of N boards.

// Constraints
// 1<=N<=100000
// 1<=K<=100000
// 1<=T<=1000000
// 1<=Li<=100000

// Output Format
// Return minimum time required to paint all boards % 10000003.

// Sample Input
// 2 2 5
// 1 10
// Sample Output
// 50

// Explanation
// The first painter can paint the first board in 5 units of time and 
// the second painter will take 50 units of time to paint the second board. 
// Since both can paint simultaneously , the total time required to paint both the boards is 50.



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(long long int mid,long long int k,long long int a[],long long int n){
    long long int painters=1;
    long long int minutes=0;
    for(int i=0;i<n;i++){
        if(minutes+a[i] > mid ){
            minutes=a[i];
            painters++;
            if(painters>k){
                return false;
            }   
        }
        else{
            minutes = minutes + a[i];
        }
    }
    
    return true;
}

int main() {
    long long int n,k,t;
    cin>>n>>k>>t;
    
    long long int a[n];
    long long int maximum=INT_MIN;
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        cin>>a[i];
        a[i]=a[i]*t;
        maximum=max(maximum,a[i]);
        sum=sum+a[i];
    }
    
    long long int s=maximum;
    long long int e=sum;
    
	
    long long int ans=0;
    while(s<=e){
        long long int mid=(s+e)/2;
        if(check(mid,k,a,n)==true){
            ans=mid;
            e=mid-1;    
        }
        
        else{
            s=mid+1;
            
        }
    }
    cout<<ans%10000003;
	return 0;
}
