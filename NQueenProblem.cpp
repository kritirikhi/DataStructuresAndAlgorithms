#include <iostream>
using namespace std;

bool queenSafe(int board[10][10],int i,int j,int n){

    // the column check
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    // right diagonal check  
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    // left diagonal check
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    // queen is safe at this position
    return true;
}

bool solveNQueen(int board[10][10],int i,int n){

    // base case
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<" Q ";
                }
                else{
                    cout<<" _ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    // ============================================================

    // rec case

    // to check the queen in the current row by chckong all the columns of the current row
    for(int j=0;j<n;j++){
        if(queenSafe(board,i,j,n)){
            board[i][j]=1;
            // to ckeck if placing the queen in i,j yields the sol or not!
            bool nextQueenSafe=solveNQueen(board,i+1,n);
            if(nextQueenSafe){
                return true;
            }
            // if not yield the sol BACKTRACK
            board[i][j]=0;
        }
    }
    return false;
}
int main() {
    int n;
    cin>>n;

    int board[10][10]={0};

    solveNQueen(board,0,n);
}
