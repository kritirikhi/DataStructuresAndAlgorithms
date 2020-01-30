#include <iostream>
using namespace std;

int clearBits(int n,int i,int j){
    int a= ~(0) << (j+1);
    int b= (1<<i)-1;
    int mask=a|b;
    return n&mask;
}

int main() {
    int n,m;
    cin>>n>>m;

    int i,j;
    cin>>i>>j;

    int clearNo=clearBits(n,i,j);
    m=m<<i;
    int finalans = clearNo|m;
    cout<<finalans;
}
