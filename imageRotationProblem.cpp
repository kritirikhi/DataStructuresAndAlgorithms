#include <iostream>
using namespace std;
int main() {
    int a[100][100];
    int r,c;
    cin>>r>>c;
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    cout<<"original matrix"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<"        ";
        }
        cout<<endl;
    }

    //transpose of matrix
    cout<<"transpose of matrix"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;(j-i)!=0;j++){
            int temp=0;
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<"        ";
        }
        cout<<endl;
    }


    //mirror reflection
    cout<<"original matrix after rotation by 90 degrees"<<endl;
    int n=c/2;
    for(int i=0;i<r;i++){
        for(int j=0;j<n;j++){
            int temp=0;
            temp=a[i][j];
            a[i][j]=a[i][c-j-1];
            a[i][c-j-1]=temp;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<"        ";
        }
        cout<<endl;
    }

}
