//                                                              KRUSKAL'S ALGORITHM

// The algorithm is to find the minimum spanning tree
// spanning tree is a connected graph with no cycle present in it      
// given the edges and the weight of the edges, we have to find the minimum weighted spanning tree 

// Algorithm 
//========================================================================================================================================================================
// sort the edges in increasing order of their weights 
// take the edges one by one from the sorted order
// if the edge on including in the tree generates a cycle then that edge will not be the part of the spanning tree ans we will move to the next edge 

// whether the edge generates a cycle or not??
// this will be checked via DISJOINT SET DATA STRUCTURE 
// every edge has two vertices
// if super parent of those 2 vertices are same then that means the vertices are already present in the current connected component and if the edge will be included then that
// will generate a cycle
// else make union of the two vertices of the edge, this will add them to the current connected component

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class dsu{
 public:
    int n;
    vector<int> par;
 
    dsu(int V){
        n=V;
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int getSuperPar(int x){
        if(x==par[x]){
            return x;
        }
        
        else{
            return par[x]=getSuperPar(par[x]);
        }
    }
    
    void unite(int x,int y){
        int superParx=getSuperPar(x);
        int superPary=getSuperPar(y);
        if(superParx != superPary){
            par[superParx]=superPary; 
        }
    }
};

int main() {
	int n,m;
	cin>>n>>m;

	vector<vector<int>> edges(m);
	for(int i=0;i<m;i++){
	    int x,y,w;
	    cin>>x>>y>>w;
	   // x--;
	   // y--;
	    edges[i]={w,x,y};
	}
	
	sort(edges.begin(),edges.end());

    dsu g(n);
    
	int ans=0;
	for(int i=0;i<m;i++){
	    int wt=edges[i][0];
	    int x=edges[i][1];
	    int y=edges[i][2];
	    
	    if(g.getSuperPar(x) != g.getSuperPar(y)){
	        g.unite(x,y);
	        ans=ans+wt;
	    }
	}
	
	cout<<ans;
	return 0;
}
