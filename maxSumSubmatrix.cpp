#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[3][3];
    int r=3,c=3;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    // suffix matrix col wise addition
    for(int i=r-1;i>=0;i--){
        for(int j=c-2;j>=0;j--){
            a[i][j]=a[i][j+1] + a[i][j];
        }
    }
    // final suffix matrix row wise addition
    for(int j=c-1;j>=0;j--){
        for(int i=r-2;i>=0;i--){
            a[i][j]=a[i][j] + a[i+1][j];
        }
    }
    //creation of temporary array
    int temp[100]={0};
    int k=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            temp[k]=a[i][j];
            k++;
        }
    }

    // printing max element that is max sum of the submatrix among all the sub matrices

    sort(temp,temp+r*c);
    int maximum=temp[r*c-1];
    cout<<"max sum of the submatrix is "<<maximum<<endl;

    //searching max sum element from the suffix matrix and getting the index and printing the required sub matrix having that very max sum
    int tli,tlj;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (a[i][j]==maximum){
                tli=i;
                tlj=j;
            }
        }
    }

    cout<<"the submatrix begins at index "<<tli<<" , "<<tlj; 

    
   
}
