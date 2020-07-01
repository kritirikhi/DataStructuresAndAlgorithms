//                                                          TO CHECK WHETHER THE GIVEN UNDIRECTED GRAPH IS A TREE OR NOT ??

// the graph with a cycle can never be the tree 
// hence we have to detect the cycle in the undirected graph 
// if cycle detected the graph is not a tree else its a tree 


// APPROACH

// we will do the BFS
// if the there comes a node which is visited already then that means the cycle is present 
// also make a check that neighbour of current node is not the parent of the current node

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;          // no of verties in graph
    list<int> *l;   // array of lists
  
    Graph(int vertices){
        V=vertices;
        l=new list<int> [V] ;  // the array of lists is initialised during run time
    }
  
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    
    bool isTree(){
        bool *visited=new bool [V];
        int *parent=new int [V];
        
        for(int i=0;i<V;i++){
            visited[i]=false;
            parent[i]=i;
        }
        
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int neigh:l[node]){
                if(visited[neigh]==true and parent[node]!=neigh){
                    return false;
                }
                else if(visited[neigh]==false){
                    visited[neigh]=true;
                    parent[neigh]=node;
                    q.push(neigh);
                }
            }
        }
        
        return true;
        
    }
};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(1,2);
    //g.addEdge(0,3);

   
    if(g.isTree()){
        cout<<"Graph is a Tree";
    }
    else{
        cout<<"Graph is not a Tree";
    }
	return 0;
}
