#include<iostream>
using namespace std;

bool subsetSum(int a[],int i,int n,int sum,int count){
	if(i==n){
		if(sum==0 && count>0){
			return true;
		}
		else {
			return false;
		}
	}
   
    // including the chaarcter
	bool x=subsetSum(a,i+1,n,sum+a[i],count+1);
   
    // excluding the characer
	bool y=subsetSum(a,i+1,n,sum,count);

	return x||y;
}

int main() {
	int t;
	cin>>t;

	for(int x=0;x<t;x++){
		int n;
		cin>>n;

		int a[n];
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int sum=0,count=0,k=0;
		cout<<subsetSum(a,k,n,sum,count);
	}
	return 0;
}