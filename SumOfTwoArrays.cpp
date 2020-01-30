#include<iostream>
#include<math.h>
using namespace std;

int arraysum(int x[],int n,int y[],int m){
    int num1=0;
    int power1=n-1;
    for(int i=0;i<n;i++){
        num1=num1+x[i]*pow(10,power1);
        power1--;
    }
    
    int num2=0;
    int power2=m-1;
    for(int i=0;i<m;i++){
        num2=num2+y[i]*pow(10,power2);
        power2--;
    }
    return num1+num2;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    int arraysums;
    arraysums=arraysum(a,n,b,m);
    int temp[m+n];
    int z=0;
    int size=0;
	while(arraysums!=0){
        int rem ;
        rem=arraysums%10;
        temp[z]=rem;
        z++;
        size++;
        arraysums=arraysums/10;

    }
    for(int i=size-1;i>=0;i--){
        cout<<temp[i]<<", ";
    }
    cout<<"END";
    return 0;
}