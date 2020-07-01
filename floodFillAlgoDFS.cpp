//              FLOODFILL BASIC
#include <iostream>
using namespace std;

int r,c;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

void printMat(char mat[][50]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}

void floodfill(char mat[][50],int i,int j,char ch,char color){
    if(i<0 || j<0 || i>=r || j>=c){
        return;
    }    
    if(mat[i][j]!=ch){
        return;
    }
    
    mat[i][j]=color;
    
    // recursive call on 4 neighbours
    for(int k=0;k<4;k++){
        floodfill(mat,i+dx[k],j+dy[k],ch,color);
    }
}

int main() {
    cin>>r>>c;
    
	char input[15][50];
	for(int i=0;i<r;i++){
	    for(int j=0;j<c;j++){
	        cin>>input[i][j];
	    }
	}
	
	printMat(input);
	floodfill(input,8,13,'.','r');
	printMat(input);
	return 0;
}
