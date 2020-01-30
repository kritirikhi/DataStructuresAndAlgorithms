#include <iostream>
using namespace std;

void sorting(int a[],int output[],int out_index,int si,int ei,int mid,int e){
    // base case
    if(si>mid && ei>e){
        // print output array
        for(int x=0;x<=e;x++){
            cout<<output[x]<<" ";
        }
        return;
    }
    output[out_index]=a[si];
    output[out_index+1]=a[ei];
    sorting(a,output,out_index+2,si+1,ei+1,mid,e);
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int mid=(0+n-1)/2;
    int output[n];
    sorting(a,output,0,0,mid+1,mid,n-1);
    
}
