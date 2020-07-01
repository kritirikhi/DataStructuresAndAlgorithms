//                                          ROBOT PATH PROBLEM (CODE CHEF)
// A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell. 
// The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions. 
// That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid.
// Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. 
// Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).

// Since the answer can get very large, output the answer modulo 1000000007.

// Input
// The first line contains 3 integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively.
// In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.

// Output
// Output should contain a single integer, the number of paths modulo 1000000007

// Example
// Input
// 4 3 2
// 3 3
// 3 1

// Output
// 2

// Explanation
// The only 2 possible paths are
// (1, 1) -> (1, 2) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3) and
// (1, 1) -> (2, 1) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3)



#include <iostream>
using namespace std;

// dp array declaration
long long int dp[1005][1005];
long long int robotPath(long long int r,long long int c){
    
    // if 1st cell is blocked then there is no way to reach the destination
    if(dp[0][0]==-1){
        return 0;
    }
    
    // base case1 
    // the 1st row will be initialised to 1 as there is only one way ot reach each cell of the 1st row 
    // if obstacle occurs then the cells after the cell wid obstacle will be zero as there is no way to reach there
    for(long long int i=0;i<c;i++){
        if(dp[0][i]==-1){
            break;
        }
        dp[0][i]=1;
    }
    
    // base case2
    // the 1st col will be initialised to 1 as there is only one way ot reach each cell of the 1st col 
    // if obstacle occurs then the cells after the cell wid obstacle will be zero as there is no way to reach there
    for(long long int i=0;i<r;i++){
        if(dp[i][0]==-1){
            break;
        }
        dp[i][0]=1;
    }
    
    
    // for each (i,j)th cell (not wid obstacle) there are 2 ways to reach there :-
    //     from top cell (i-1,j)th cell
    //     from left cell (i,j-1)th cell
        
    //     if the above two options are not the obstacles then the (i,j)th cell will be dp[i-1,j]+dp[i,j-1]
    //     if any of the two or both are obstacles then we will avoid that i.e not take it into considertion
    for(long long int i=1;i<r;i++){
        for(long long int j=1;j<c;j++){
            if(dp[i][j]==-1){
                continue;
            }
            dp[i][j]=0;
            if(dp[i-1][j]!=-1){
                dp[i][j]=dp[i-1][j];
                dp[i][j]=dp[i][j]%1000000007;
            }
            
            if(dp[i][j-1]!=-1){
                dp[i][j]+=dp[i][j-1];
                dp[i][j]=dp[i][j]%1000000007;
            }
        }
    }
    
    if(dp[r-1][c-1]==-1){
        return 0;
    }
    return dp[r-1][c-1];
    
}

int main() {
    
    long long int r,c,p;
    cin>>r>>c>>p;
    
    // initialised dp array
    for(long long int i=0;i<r;i++){
        for(long long int j=0;j<c;j++){
            dp[i][j]=0;
        }
    }
    
    // adding obstacles to the dp array
    for(long long int x=0;x<p;x++){
        long long int xcood,ycood;
        cin>>xcood>>ycood;
        dp[xcood-1][ycood-1]=-1;
    }
    
    // Function calling
    cout<<robotPath(r,c)<<endl;
	return 0;
}
