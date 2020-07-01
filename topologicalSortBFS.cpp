//                                                                      TOPOLOGICAL SORT using BFS

// APPROACH
// we have to calculate first the indegree of all the vertices
// the vertices with indegree 0 means that those vertices are not dependent
// we will push the vertices with 0 indegree to the queue
// repeat the following steps till the queue is not empty
//      pop the front element
//      make the indegree of the neighbours of the popped element decreased by 1 
//      if the decreased indegree becomes 0 then push that neighbour in the queue

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
  
  
    // func to add edge that edge between node x and node y
    void addEdge(int x,int y){
        l[x].push_back(y);
    }
    
    void topologicalSort(){
        int *indegree=new int [V];
        
        for(int i=0;i<V;i++){
            indegree[i]=0;
        }
        
        for(int i=0;i<V;i++){
            for(auto neigh:l[i]){
                indegree[neigh]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            
            for(auto neigh:l[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        
        
        
    }
};

int main() {
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
 
    g.topologicalSort();
	return 0;
}
