#include <iostream>
using namespace std;

int tiling(int n){
    if(n==1 | n==2){
        return n;
    }
    int x=tiling(n-1);
    int y=tiling(n-2);
    return x+y;
}

int main() {
    int n;
    cin>>n;

    cout<<"Number of ways to tile the board are "<<tiling(n);

}
