#include <iostream>
using namespace std;
int main() {
    int a[100]={0};
    a[0]=0;
    int num=5;
    for(int i=1;i<100;i++){
        a[i]=num;
        num=num+2;
    }
    int n;
    cin>>n;
    int index;
    for(int i=0;i<100;i++){
        if(a[i]==n){
            index=i;
            break;
        }
    }
    // first line of the pattern
    cout<<"*";
    int count=1;
    for(int j=1;j<=index;j++){
        cout<<" ";
        count++;
    }
    for(int j=count+1;j<=n;j++){
        cout<<"*";
    }
    cout<<endl;

    // first half of the pattern
    for(int i=2;i<=n/2;i++){
        cout<<"*";
        for(int k=1;k<=index;k++){
            cout<<" ";
        }
        cout<<"*"<<endl;
    }
    // mid of the pattern
    for(int k=1;k<=n;k++){
        cout<<"*";
    }
    cout<<endl;

    // lower half
    for(int k=1;k<n/2;k++){
        for(int i=1;i<=n-2-index;i++){
            cout<<" ";
        }
        cout<<"*";
        for(int k=1;k<=index;k++){
            cout<<" ";
        }
        cout<<"*"<<endl;
    }
    // last line of the pattern
    for(int i=1;i<=n-index-1;i++){
        cout<<"*";
    }
    for(int k=1;k<=index;k++){
        cout<<" ";
    }
    cout<<"*"  ;
    return 0;
}