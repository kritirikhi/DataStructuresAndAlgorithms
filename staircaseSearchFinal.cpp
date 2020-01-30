#include <iostream>
using namespace std;
int main() {
    int r,c;
    cin>>r>>c;
    int a[100][100];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    int key;
    cin>>key;
    int i=0;
    int j=c-1;
    while(i<r && j>=0){
        if(a[i][j]==key){
            cout<<"found at index "<<i<<" , "<<j<<endl;
            break;
        }
        else if(a[i][j]<key){
            i++;
        }
        else{
            j--;
        }
    }

    if(i>=r || j<0){
        cout<<"not found"<<endl;
    }
    return 0;
}
