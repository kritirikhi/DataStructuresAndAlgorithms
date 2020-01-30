#include <iostream>
using namespace std;

int binarySearch(int *a,int n,int key,int s,int e,int mid){
    if(s>e){
        return -1;
    }
    else if(key==a[mid]){
        return mid;
    }
    else if(key<a[mid]){
        return binarySearch(a,n,key,s,mid-1,(s+mid-1)/2);
    }
    else if(key>a[mid]){
        return binarySearch(a,n,key,mid+1,e,(mid+1+e)/2);
    }
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

    int s=0,e=n-1,mid=(s+e)/2;
    cout<<binarySearch(a,n,key,s,e,mid);
}
