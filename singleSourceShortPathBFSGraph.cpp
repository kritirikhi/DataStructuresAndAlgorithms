//                                              SINGLE SOURCE SHORTEST PATH USING BFS (unweighted graph)

// the shortest dist of the particular node from the source node will be equal to (shortest dist of the parent node from source + 1)
// this can be achieved by the breadth first search
// if there are more than 1 paths to reach a node then the path reaching the node first will be the shortest path from the source to that node

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int,list<int>> l;
    
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void BFS(int src){
        queue<int> q;
        // to store the dist of the node from the source (the path which reaches the node first)
        map<int,int> dist;
        
        
        // initialising all the distances to infinity
        for(auto node_pair:l){
            int node=node_pair.first;
            dist[node]=INT_MAX;
        }
        
        // the dist of source node to source node = 0 
        dist[src]=0;
        q.push(src);
        
        // finding distances of all the nodes
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto neigh:l[node]){
                if(dist[neigh]==INT_MAX){
                    q.push(neigh);
                    dist[neigh]=dist[node]+1;
                 //   cout<<neigh<<" "<<dist[neigh]<<" "<<dist[node]<<endl;
                }
            }
        }
        
        // printing the distances
        for(auto nodePair:l){
            int node=nodePair.first;
            int d=dist[node];
            cout<<node<<" dist from src "<<d<<endl;
        }
        
    }
};

int main() {
    Graph g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	
	g.BFS(0);
	return 0;
}
