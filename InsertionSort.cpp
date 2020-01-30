#include <iostream>
using namespace std;
void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int no=a[i];
        int j=i-1;
        for(;j>=0 && a[j]>no;j--){
            a[j+1]=a[j];
        }
        a[j+1]=no;
    }
}
int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    insertionSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"   ";
    }
}
