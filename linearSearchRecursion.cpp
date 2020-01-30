#include <iostream>
using namespace std;

// prateek sir method
// int linearSearch(int *a,int n,int key,int index){
//     if(index==n){
//         return -1;
//     }
//     if(a[index]==key){
//         return index;
//     }
//     return linearSearch(a,n,key,index+1);
// }

// mine method
int linearSearch(int *a,int n,int key,int index){
    if(n==0){
        return -1;
    }
    if(a[0]==key){
        return index;
    }
    return linearSearch(a+1,n-1,key,index+1);
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

    cout<<linearSearch(a,n,key,0);
}
