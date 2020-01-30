#include <iostream>
using namespace std;
int main() {
    int q;
    cin>>q;
    int query[100][4]={0};
    for(int i=0;i<q;i++){
        for(int j=0;j<4;j++){
            cin>>query[i][j];
        }
    }

    int a[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    int r=3,c=3;

    //prefix matrix col wise addition
    for(int i=0;i<r;i++){
        for(int j=1;j<c;j++){
            a[i][j]=a[i][j-1]+a[i][j];
        }
    }

    // final prefix matrix addition row wise
    for(int j=0;j<c;j++){
        for(int i=1;i<r;i++){
            a[i][j]=a[i][j]+a[i-1][j];
        }
    }
   // printing sum of the submatrix given in the query
    for(int i=0;i<q;i++){
        int sum=0;
        int tli=query[i][0];
        int tlj=query[i][1];
        int bri=query[i][2];
        int brj=query[i][3];

        int p=a[tli-1][brj];
        int q=a[bri][tlj-1];
        int r=a[tli-1][tlj-1];
        int v=a[bri][brj];

        if((tli-1)<0){
            p=r=0;
        }
        else if( (tlj-1)<0 ){
            q=r=0;
        }
        sum = v-p-q+r;
        cout<<sum<<endl;
    }
}
