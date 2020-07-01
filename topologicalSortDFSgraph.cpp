//                                                                  TOPOLOGICAL SORT using DFS 

// In a dependency graph there exists a lot of dependencies 
// we have to find the linear ordering in which the tasks are to be performed
// that linear ordering of a dependency graph is called a topological sort 

// this algo does not work on a cyclic graph 
// it works well on a directed acyclic graph

// Approach
// traverse the graph via DFS 
// after traversing all the dependencies of source node i.e neighbours of the source node push that source node at the front of the list 
// repeat this for all the nodes which are not traversed i.e not visited

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename t>
class Graph{
    unordered_map<t,list<t>> l;
public:
    void addEdge(t x, t y){
        // directed graph so add directed edge only
        l[x].push_back(y);
    }
    
    void dfs_helper(t src,map<t,bool> &visited, list<t> &ordering){
        visited[src]=true;
        
        for(auto neigh: l[src]){
            if(!visited[neigh]){
                dfs_helper(neigh,visited,ordering);   
            }
        }
        
        ordering.push_front(src);
    }
    
    void dfs(){
        map<t,bool> visited;
        list<t> ordering;
        for(auto node_pair:l){
            visited[node_pair.first]=false;
        }
        
        for(auto nodePair:l){
            t node=nodePair.first;
            if(!visited[node]){
                dfs_helper(node,visited,ordering);
            }
        }
        
        for(auto x:ordering){
            cout<<x<<endl;
        }
    }
};

int main() {
    Graph<string> g;
    g.addEdge("python","dataprocessing");
    g.addEdge("python","pytorch");
    g.addEdge("python","ml");
    g.addEdge("dataprocessing","ml");
    g.addEdge("pytorch","dl");
    g.addEdge("ml","dl");
    g.addEdge("dl","faceRecog");
    g.addEdge("dataset","faceRecog");
    
    g.dfs();
	return 0;
}
