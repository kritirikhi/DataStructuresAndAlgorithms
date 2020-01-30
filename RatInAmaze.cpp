#include <iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int sol[10][10],int i,int j,int m,int n){
    // base case
    if(i==m && j==n){
        sol[m][n]=1;
        // printing the sol array
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    // rec case

    /// rat out of the grid
    if(i>m || j>>n){
        return false;
    }
    // if obstacle comes
    if(maze[i][j]=='X'){
        return false;
    }

    sol[i][j]=1;

    bool forwardSuccess=ratInMaze(maze,sol,i,j+1,m,n);
    bool downSuccess=ratInMaze(maze,sol,i+1,j,m,n);

    sol[i][j]=0;   // backtracking

    if(forwardSuccess || downSuccess){
        return true;
    }
    return false;
}

int main() {
    char maze[10][10]={"0XXX","00X0","X0XX","0000"};
    int sol[10][10]={0};
    int m=4,n=4;
    ratInMaze(maze,sol,0,0,m-1,n-1);
}