#include <iostream>
using namespace std;

int tiling(int n){
    if(n==1 || n==2 || n==3){
        return 1;
    }
    if(n==4){
        return 2;
    }

    int x=tiling(n-1);
    int y=tiling(n-4);
    return x+y;
}

int main() {
    int n;
    cin>>n;

    cout<<"Number of ways to tile the board are "<<tiling(n);

}
