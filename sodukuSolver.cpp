#include <iostream>
#include<math.h>
using namespace std;

bool canPlace(int mat[9][9],int i,int j,int n,int number){
    // if present in col or row
    for(int x=0;x<n;x++){
        if( mat[x][j]==number || mat[i][x]==number){
            return false;
        }
    }

    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int k=sx;k<sx+rn;k++){
        for(int l=sy;l<sy+rn;l++){
            if(mat[k][l]==number){
                return false;
            }
        }
    }

    return true;
}

bool solveSoduku(int mat[9][9],int i,int j,int n){
    // base case
    if(i==n){

        // print the matrix
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                cout<<mat[a][b]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    // if col ends
    if(j==n){
        return solveSoduku(mat,i+1,0,n);
    }
    // if already a number presents

    if(mat[i][j]!=0){
        return solveSoduku(mat,i,j+1,n);
    }

    // rec case
    else{
        for(int number=1;number<=n;number++){
            if(canPlace(mat,i,j,n,number)){
                mat[i][j]=number;
                bool canSolve=solveSoduku(mat,i,j+1,n);
                if(canSolve==true){
                    return true;
                }
            }
        }

        // backtracking
        mat[i][j]=0;
        return false;
    }
}

int main() {
    int mat[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},  
        {5, 2, 0, 0, 0, 0, 0, 0, 0},  
        {0, 8, 7, 0, 0, 0, 0, 3, 1},  
        {0, 0, 3, 0, 1, 0, 0, 8, 0},  
        {9, 0, 0, 8, 6, 3, 0, 0, 5},  
        {0, 5, 0, 0, 9, 0, 6, 0, 0},  
        {1, 3, 0, 0, 0, 0, 2, 5, 0},  
        {0, 0, 0, 0, 0, 0, 0, 7, 4},  
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };  

    int n=9;
    solveSoduku(mat,0,0,n);
    return 0;
}
