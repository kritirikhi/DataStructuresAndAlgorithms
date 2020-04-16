#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int merge(int a[],int temp[],int left,int mid,int right){
    int i=left;
    int j=mid;
    int k=left;
    int invCount=0;
    
    while(i<=mid-1 && j<=right){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
            invCount+=(mid-i);
        }
    }
    
    while(i<=mid-1){
        temp[k++]=a[i++];
    }
    
    while(j<=right){
		temp[k++]=a[j++];        
    }
    
    for(int x=left;x<=right;x++){
        a[x]=temp[x];
    }
    return invCount;
}


long long int mergeSort(int a[],int temp[],int left,int right){
    int invCount=0;
    int mid;
    if(right>left){
        mid=(left+right)/2;
        invCount+=mergeSort(a,temp,left,mid);
        invCount+=mergeSort(a,temp,mid+1,right);
        
        invCount+=merge(a,temp,left,mid+1,right);
    }
    return invCount;
}
  

long long solve(int a[], int n){
    int temp[n];
    long long int ans=mergeSort(a,temp,0,n-1);
    return ans;
}


int main(){
    long long int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    long long int ans=solve(a,n);
    cout<<ans;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}