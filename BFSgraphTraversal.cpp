//                                                              BREADTH FIRST SEARCH in GRAPH

// Breadth first search in graph is similar to level order traversal in tree
// push the source node in queue
// mark it as visited
// pop it 
// print it
// add all its neighbours to the queue
// mark those neighbours as visited too
// repeat the procedure till the queue is empty

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// templated class 
template <typename t>
class Graph{
public:
    map<t,list<t>> l;
    
    void addEdge(t x , t y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    // BFS traversal 
    void bfs(t src){
        map<t,bool> visited;
        queue<t> q;
        
        q.push(src);
        visited[src]=true;
        
        while(!q.empty()){
            t node=q.front();
            q.pop();
            cout<<node<<" ";
            
            for(auto neigh:l[node]){
                if(visited[neigh]!=true){
                    q.push(neigh);
                    visited[neigh]=true;
                }
            }
        }
    }
};

int main() {
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	
	g.bfs(0);
	return 0;
}
