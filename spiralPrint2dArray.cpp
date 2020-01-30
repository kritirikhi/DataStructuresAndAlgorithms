#include <iostream>
using namespace std;
int main() {
    int a[100][100];
    int r,c;
    cin>>r>>c;
     int value=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            a[i][j]=value++;
        }
    }

    cout<<"original array"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<"        ";
        }
        cout<<endl;

    }

    cout<<"spiralprint"<<endl;

    int startrow=0,endcol=c-1,endrow=r-1,startcol=0;

    while(startrow<=endrow && startcol<=endcol){
        
        // start row
        for(int i=startcol;i<=endcol;i++){
            cout<<a[startrow][i]<<"  ";
        }
        startrow++;

        //end col
        for(int i=startrow;i<=endrow;i++){
            cout<<a[i][endcol]<<"  ";
        }
        
        endcol--;

        // end row
        if(endrow>startrow){
        for(int i=endcol;i>=startcol;i--){
            cout<<a[endrow][i]<<"  ";
        }
        }
        endrow--;

        //start col
        if(startcol<endcol){
        for(int i=endrow;i>=startrow;i--){
            cout<<a[i][startcol]<<"  ";
        }
        }
        startcol++;
    }

}
