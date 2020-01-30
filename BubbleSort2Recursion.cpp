#include <iostream>
using namespace std;

// void bubbleSort(int a[],int n){
//     if(n==1){
//         return;
//     }

//     for(int i=0;i<=n-2;i++){
//         if(a[i]>a[i+1]){
//             swap(a[i],a[i+1]);
//         }
//     }
//     bubbleSort(a,n-1);
// }

void bubbleSort2(int a[],int n,int j){
    if(n==1){
        return;
    }
    if(j==n-1){
        return bubbleSort2(a,n-1,0);
    }

    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    return bubbleSort2(a,n,j+1);
   // return;

}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    bubbleSort2(a,n,0);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}
