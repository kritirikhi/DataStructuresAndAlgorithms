#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void shuffle(int a[],int s,int e){
    srand(time(NULL));
    for(int i=e;i>0;i--){
        int j=rand()%(i+1);
        swap(a[i],a[j]);
    }
}

int partition(int a[],int s,int e){
    int pivot=a[e];
    int i=s-1;
    int j=s;
    for(;j<e;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quickSort(int a[],int s,int e){

    if(s>=e){
        return;
    }
    int p=partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    shuffle(a,0,n-1);
    cout<<"shuffled array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;

    quickSort(a,0,n-1);
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}
