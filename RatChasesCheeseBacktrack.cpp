#include <iostream>
using namespace std;

bool ratInMaze(char maze[1000][1000],int sol[1000][1000],int i,int j,int m,int n){
    // base case
    if(i==m && j==n && maze[i][j]!='X'){
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
    if(i>m || j>n || i<0 || j<0){
        return false;
    }
    // if obstacle comes
    if(maze[i][j]=='X'){
        return false;
    }

    sol[i][j]=1;
	bool path=false;

    bool left,right,down,up;
    if(sol[i][j+1]==0){
        left=ratInMaze(maze,sol,i,j+1,m,n);
    }
    if(sol[i+1][j]==0){
        down=ratInMaze(maze,sol,i+1,j,m,n);
    }
    if(sol[i][j-1]==0){
        right=ratInMaze(maze,sol,i,j-1,m,n); 
    }
    if(sol[i-1][j]==0){
        up=ratInMaze(maze,sol,i-1,j,m,n); 
    }

    sol[i][j]=0;   // backtracking

	if(left||right||down||up){
		path=true;
		return true;
	}

    sol[i][j]=0;

    return path;
}

int main() {
    int m,n;
    cin>>m>>n;
     char maze[1000][1000];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
	    }
    }
    int sol[1000][1000]={0};

    bool ans=ratInMaze(maze,sol,0,0,m-1,n-1);	

    if(ans==false){
	    cout<<"NO PATH FOUND";
    }
}