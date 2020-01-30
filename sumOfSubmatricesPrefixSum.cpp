#include <iostream>
using namespace std;
int main() {
     int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
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
int sum=0;
    for(int tli=0;tli<r;tli++){
        for(int tlj=0;tlj<c;tlj++){
            for(int bri=tli;bri<r;bri++){
                for(int brj=tlj;brj<c;brj++){
                    int p=a[tli-1][brj];
                    int q=a[bri][tlj-1];
                    int r=a[tli-1][tlj-1];
                    int v=a[bri][brj];

                    if((tli-1)<0){
                        p=r=0;
                    }
                    if( (tlj-1)<0 ){
                        q=r=0;
                    }
                    sum = sum+v-p-q+r;
                }
            }
        }
    }
    cout<<sum;
    return 0 ;
}
