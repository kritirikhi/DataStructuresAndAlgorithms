#include <iostream>
using namespace std;

void merge(int a[],int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int k=s;
    int j=mid+1;
    int temp[100];

    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }

        while(i<=mid){
            temp[k++]=a[i++];
        }
        while(j<=e){
            temp[k++]=a[j++];
        }

        for(int i=s;i<=e;i++){
            a[i]=temp[i];
        }
    }
}

void mergerSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;

    mergerSort(a,s,mid);
    mergerSort(a,mid+1,e);

    merge(a,s,e);
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergerSort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}
