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
    
    void dfs_helper(t src,map<t,bool> &visited){
        cout<<src<<" ";
        visited[src]=true;
        
        for(auto neigh: l[src]){
            if(!visited[neigh]){
                dfs_helper(neigh,visited);   
            }
        }
    }
    
    void dfs(t src){
        map<t,bool> visited;
        for(auto node_pair:l){
            visited[node_pair.first]=false;
        }
        
        dfs_helper(src,visited);
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	
    g.dfs(0);
	return 0;
}
