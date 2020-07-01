//                                                              DETECT A CYCLE IN A DIRECTED GRAPH

// given a directed graph, check whether the cycle exists or not

// APPROACH

// we will trace two things
//     whether the node is visited
//     the current path going on 
    
// if the the neigh of the current node is already present in the current path then that means a back edge exits i.e CYCLE EXISTS 
// if the node is not visited we will check whether cycle exists at its neighbours or not

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V=V;
        l = new list<int> [V];
    }
    
    
    // adding edges in the directed graph
    void addEdge(int x,int y){
        l[x].push_back(y);
    }
    
    // recursive function
    bool helper_cycle(int node, bool* visited, bool *stack){
        visited[node]=true;     // to trace whether the node is visited or not 
        stack[node]=true;       // to trace whether the node is present in the current path
        
        // checking for the neighbours of the current node
        for(auto neigh:l[node]){
            // if neigh already present in the current path
            if(stack[neigh]==true){  
                return true;
            }
            
            // if neighbour is not visited before
            else if(visited[neigh]==false){
                // Does cycle exists on neighbour or not
                bool isCycle = helper_cycle(neigh,visited,stack);
                if(isCycle){
                    return true;
                }
            }
        }
        
        stack[node]=false;
        return false;
    }
    
    bool detectCycle(){
        bool *visited=new bool[V];      // to trace whether the node is visited or not 
        bool *stack=new bool[V];        // to trace whether the node is present in the current path
        
        // initialising the visited and stack arrays to false
        for(int i=0;i<V;i++){
            visited[i]=false;
            stack[i]=false;
        }
        
        return helper_cycle(0,visited,stack);
        
    }
};

int main() {
    
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2);     // back edge
    
    if(g.detectCycle()){
        cout<<"Cycle is Present";
    }
    else{
        cout<<"Cycle is not Present";
    }
    
	return 0;
}
