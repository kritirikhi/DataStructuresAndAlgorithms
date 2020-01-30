#include <iostream>
using namespace std;

void MaxRowSum(int a[][100], int row, int col){

    int maximum=0;
    cout<<"original array"<<endl;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            cout<<a[i][j]<<"        ";
            sum=sum+a[i][j];
        }
        maximum=max(maximum,sum);
        cout<<endl;

    }
    cout<<endl<<"max sum row wise is"<<maximum;

}

void MaxColSum(int a[][100],int r,int c){
    int maximum=0;
    cout<<endl;
    for(int j=0;j<c;j++){
        int sum=0;
        for(int i=0;i<r;i++){
            sum=sum+a[i][j];
            //cout<<a[i][j]<<"        ";
        }
        //cout<<endl;
        maximum=max(maximum,sum);
    }
     cout<<endl<<"max sum column wise is"<<maximum;
}
int main() {
   int a[100][100];
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
          cin>>a[i][j];
        }
    }
    MaxRowSum(a,r,c );
    MaxColSum(a,r,c);  

}
