#include<iostream>
using namespace std;

int * search(int *a,int *b,int key,int n,int i,int j){
	if(i==n){
		return 0;
	}
	if(a[i]==key){
		b[j]=i;
         search(a,b,key,n,i+1,j+1);
	}
    else{
        search(a,b,key,n,i+1,j);
    }
	return b;
}  

int main() {
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int key;
	cin>>key;

	int b[n]={0};
	int *ptr=search(a,b,key,n,0,0);
    cout<<b[0]<<" ";
	for(int i=1;i<n;i++){
        if(b[i]!=0){
            cout<<b[i]<<" ";
        }   
	}
    return 0;
}