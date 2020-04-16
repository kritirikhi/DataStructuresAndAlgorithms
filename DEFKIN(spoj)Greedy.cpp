//                                                                  GRAND TEMPLE (DEFKIN)  (spoj)
//  ques link is :- https://www.spoj.com/problems/DEFKIN/

// Approach:-
//      take an array of x coordinates
//      take an array of y coordinates
//      sort both the arrays
//      find max dx (max width along x axis)
//      find max dy (max heaight along y axis)
//      max area = dx*dy

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    for(int k=0;k<t;k++){
        int maxX,maxY,towers;
        cin>>maxX>>maxY>>towers;
        if(towers==0){
            cout<<maxX*maxY<<endl;
            continue;
        }
        
        int x[towers];
        int y[towers];
        
        for(int i=0;i<towers;i++){
            cin>>x[i]>>y[i];
        }
        
        sort(x,x+towers);
        sort(y,y+towers);
       
        int deltax=x[0]-1;
        int deltay=y[0]-1;
        
        for(int i=1;i<towers;i++){
            int diffX = x[ i ] - x[ i-1 ] - 1;
            int diffY = y[ i ] - y[ i-1 ] - 1;
            deltax=max(deltax ,diffX);
            deltay=max(deltay ,diffY);
        }
        deltax=max(deltax,maxX-x[towers-1]);
        deltay=max(deltay,maxY-y[towers-1]);
        
        int area=deltax*deltay;
        cout<<area<<endl;
        
    }
	return 0;
}
