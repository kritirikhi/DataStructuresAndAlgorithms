// given a graph g . Find the no of connected components of the graph

// the no of times the dfs func is called , that gives the no of connected components
// at a time the dfs func finds the path from the src node to all the nodes which are connected

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename t>
class Graph{
    unordered_map<t,list<t>> l;
public:
    void addEdge(t x, t y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void dfs_helper(t src, map<t,bool> &visited){
        cout<<src<<" ";
        visited[src]=true;
        
        for(auto neigh:l[src]){
            if(!visited[neigh]){
                dfs_helper(neigh,visited);   
            }
        }
    }
    
    void dfs(){
        map<t,bool> visited;
        for(auto nodePair:l){
            t node=nodePair.first;
            visited[node]=false;
        }
        
        int count=0; // to keep count of connected components
        for(auto nodePair:l){
            t node=nodePair.first;  
            if(!visited[node]){
                cout<<"connected component "<<count<<" => ";
                dfs_helper(node,visited);
                count++;
                cout<<endl;
            }
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);
    
    g.dfs();
	return 0;
}