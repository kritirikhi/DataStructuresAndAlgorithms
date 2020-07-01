// Problem :- To find how many numbers less than n are there which are divisible by prime numbers less than 20 i.e (2,3,5,7,11,13,17,19)

// Approach
// Use exclusion inclusion principle

//  8 prime numbers are there hence there will be 8 subsets
//  excluding the empty subset the subsets on which we have to work are 7 that will (1<<8) - 1
//  we will work on each subset from 1 to 8 
//  for ith subset calc the no of setbits for that subset 
//  then we will find that which prime nos that subset contains  
//  then no of elements less than n divisible the elements of the ith subset will be n/(product of elements in the subset) 

//  if setsbits are odd add the product of ith subset to the ans 
//  else subtract the product of ith subset from the ans 

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin>>n;
	
	int prime[]={2,3,5,7,11,13,17,19};
	int subsets=(1<<8)-1;
	int ans=0;
	for(int i=1;i<=subsets;i++){
	    int setbits=__builtin_popcount(i);
	    int denom=1;
	    for(int j=0;j<=7;j++){
	        if( i&(1<<j) ){
	            int p=prime[j];
	            denom=denom*p;
	        }
	    }
	    
	    if(setbits&1){
	        ans=ans+(n/denom);
	    }
	    else{
	        ans=ans-(n/denom);
	    }
	}
	
	cout<<ans;
	return 0;
}
