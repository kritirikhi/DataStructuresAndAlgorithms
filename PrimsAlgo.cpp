//                                                                         PRIM'S ALGORITHM

// prims is the algo for finding the minimum weighted spanning tree
// Its is diff from kruskal in a way that :- 
//     kruskal takes into consideration the edges
//     prims takes into consideration the vertices
//     prims is the greedy algorithm 
    

//ALGORITHM 

// we will randomly take one source vertex of the Graph 
// maintain an array called VISITED to mark whether the node is visited or not 
// maintain an array called PARENT to store the parent of the vertex in MST 
// maintain an array called WEIGHT to store the min weights possible at each vertex 

// 1) start from the node having minimum wt in the weight array 
// 2) traverse all its neighbours and update the weight and parent of the neighbours if (weight of neighbour > weight of edge between neighbour and source )
// 3) mark the source node as VISITED 
// 4) repeat the 1,2,3 for all the unvisited nodes and the nodes

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    unordered_map<int,list<pair<int,int>>> l;
    
    Graph(int V){
        this->V=V;
    }
    
    void addEdge(int x,int y,int wt){
        l[x].push_back(make_pair(y,wt));
        l[y].push_back(make_pair(x,wt));
    }
    
    int findMinVertex(int* weight,bool* visited,int V){
        int minVertex=-1;
        
        for(int i=0;i<V;i++){
            if(visited[i]==false && (minVertex==-1 || weight[i]<weight[minVertex])){
                minVertex=i;
            }
        }
        
        return minVertex;
    }
    
    void prims(){
        bool* visited = new bool[V];
        int* parent = new int[V];
        int* weight = new int[V];
        
        for(int i=0;i<V;i++){
            weight[i]=INT_MAX;
            visited[i]=false;
        }
            
        parent[0]=-1;
        weight[0]=0;
        
        for(int i=0;i<V;i++){
            int minVertex=findMinVertex(weight,visited,V);
             visited[minVertex]=true;
            
            for(auto neigh:l[minVertex]){
                if(visited[neigh.first]==false){
                    int vertex=neigh.first;
                    int wt=neigh.second;
                
                    if(weight[vertex]>wt){
                        weight[vertex]=wt;
                        parent[vertex]=minVertex;
                    }
                }
            }
        }
        
        for(int i=1;i<V;i++){
            cout<<i<<" "<<parent[i]<<" "<<" with weight = "<<weight[i]<<endl;
        }
    }
    
    
};

int main() {
	int n;
	cin>>n;
	Graph g(n);
	
	int m;
	cin>>m;
	
	for(int i=0;i<m;i++){
	    int x,y,wt;
	    cin>>x>>y>>wt;
	    
	    g.addEdge(x,y,wt);
	}
	
	g.prims();
	
	return 0;
}
