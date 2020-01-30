#include <iostream>
using namespace std;
int main() {

    int arr[10][10]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int n=4;
    cout<<"original matrix is"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }   

    cout<<"matrix in wave form"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i][0]<<" ";
    }

    for(int j=1;j<n;j++){
        for(int i=0;i<n;i++){
            if(j%2!=0){
                cout<<arr[n-i-1][j]<<" ";
            }
            else{

                cout<<arr[i][j]<<" ";
            }

        }
    }
}
