// Chopsticks
// link :- https://www.codechef.com/problems/TACHSTCK

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n,d;
	cin>>n>>d;

    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }

//  sort the chopsticks acc to lenght
//  if the chopstick can be paired with its neighbouur then
//      index=index+2l
//  else
//      index=index+1
	sort(a,a+n);
	
	long long int pairs=0;
	long long int idx=0;
	while(idx<n-1){
	    if(a[idx+1]-a[idx]<=d){
	        idx=idx+2;
	        pairs++;
	    }
	    else{
	        idx++;
	    }
	}

	cout<<pairs;
	return 0;
}
