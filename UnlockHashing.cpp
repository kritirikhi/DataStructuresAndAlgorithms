#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find(int a[],int n,int item){
    for(int i=0;i<n;i++){
        if(a[i]==item){
            return i;
        }
    }
}

int main() {
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int size=n;
    int j=0;
    while(k>0 && j<size){
        int index=find(a,size,n);
        if(index==j){
            j++;
            n--;
            continue;
        }
        swap(a[j],a[index]);
        j++;
        n--;
        k--;
    }

    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}
