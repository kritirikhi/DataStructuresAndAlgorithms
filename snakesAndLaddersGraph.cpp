//                                              SNAKES AND LADDERS 
// there is a board of 6x6  
// find the min no of throws required to reach the destination 36
// also find the shortest path to reach destination 36
                                                    
                                                //          BOARD 
                                                // 36  35  34  33  32  31
                                                // 25  26  27  28  29  30
                                                // 24  23  22  21  20  19
                                                // 13  14  15  16  17  18
                                                // 12  11  10   9   8   7  
                                                // 1   2   3   4   5    6

//========================================================================================================================================================                                                
//APPROACH                                               

// first store all the jumps in the boards  array 
// the jumps are the steps which are increased or decreased due to ladder or snake 
// generate the vertices from 0 to 36 and add all the edges between them 
// for ith vertex there will 6 edges possible i+1,i+2,i+3,i+4,i+5,i+6 provided all are <=36
// after the addition of the vertices, the bfs single source shortest path algo is run and the len of the shortest path is found
// also store the parent of each node so that we can backtrace the path
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int,list<int>> l;
    
    void addEdge(int x,int y){
        // directed graph
        l[x].push_back(y);
    }
    
    void BFS(int src,int dest){
        queue<int> q;
        // to store the dist of the node from the source (the path which reaches the node first)
        map<int,int> dist;
        map<int,int> parent; // to store the parent of each node to print the path
        
        
        // initialising all the distances to infinity
        for(auto node_pair:l){
            int node=node_pair.first;
            dist[node]=INT_MAX;
        }
        
        // the dist of source node to source node = 0 
        dist[src]=0;
        q.push(src);
        parent[src]=src;
        
        // finding distances of all the nodes
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto neigh:l[node]){
                if(dist[neigh]==INT_MAX){
                    q.push(neigh);
                    dist[neigh]=dist[node]+1;
                    parent[neigh]=node;
                }
            }
        }
        
        int temp=dest;
        while(parent[temp]!=temp){
            cout<<temp<<" ";
            temp=parent[temp];
        }
        cout<<src<<endl;
        cout<<"Min No. Of Dice Throws are :- "<<dist[dest];
    }
};

int main() {
    
    // storing jumps when snakes and ladders occur
    int board[50]={0};
    
    // ladders
    board[2] = 13;
    board[5] = 2 ; 
    board[9] = 18;
    board[18] = 11;
    board[25] = 10;
    
    // snakes
    board[17] = -13;
    board[24] = -8;
    board[34] = -22;
    board[32] = -2;
    board[20] = -14;
    
    Graph g;
    
    // adding edges
    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
            int j=i+dice;
            j=j+board[j];
            
            g.addEdge(i,j);
        }
    }
    
	g.BFS(0,36);
	return 0;

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
