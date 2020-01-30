#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"array in ascending order is :-"<<endl;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            for(int k=j+1;k<=n-i;k++){
                if(a[j]>a[k]){
                    int temp=a[j];
                    a[j]=a[k];
                    a[k]=temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl<<endl;

    cout<<"array in descending order is :-"<<endl;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            for(int k=j+1;k<=n-i;k++){
                if(a[j]<a[k]){
                    int temp=a[j];
                    a[j]=a[k];
                    a[k]=temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }

}
