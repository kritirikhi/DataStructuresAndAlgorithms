#include <iostream>
using namespace std;
int main() {
    int r,c;
    cin>>r>>c;
    int **a=new int* [r];

    for(int i=0;i<r;i++){
        a[i]=new int[c];
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }

    int sum=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int topleft = (i+1)*(j+1);
            int bottomright = (r-i)*(c-j);

            sum = sum + a[i][j]*topleft*bottomright;
        }
    }
    cout<<sum;
}
