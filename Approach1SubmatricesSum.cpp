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
    int sum=0;
    for(int li=0;li<r;li++){
        for(int lj=0;lj<c;lj++){
            for(int bi=li;bi<r;bi++){
                for(int bj=lj;bj<c;bj++){
                    for(int i=li;i<=bi;i++){
                        for(int j=lj;j<=bj;j++){
                            sum=sum+a[i][j];
                        }
                    }
                }
            }
        }
    }
    cout<<sum;
}
