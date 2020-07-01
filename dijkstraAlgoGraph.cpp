//                                                                                  DIJKSTRA ALGORITHM

// given a directed or undirected weighted graph , we have to find the len of shortest path from source to all other nodes 


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename t>
class Graph{
public:
    unordered_map<t,list<pair<t,int>>> l;
    
    // adding edges to graph 
    void addEdge(t x, t y,bool bidir,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir==true){
            l[y].push_back(make_pair(x,wt));
        }
    }
    
    // printing the adjacency list of the graph 
    void printAdj(){
        for(auto node_pair:l){
            t key=node_pair.first;
            cout<<key<<" => ";
            for(auto neigh:node_pair.second){
                cout<<"("<<neigh.first<<","<<neigh.second<<")"<<" ";
            }
            cout<<endl;
        }
    }
    
    
    // dijkstra's algorithhm
    void dijkstra(t src){
        
        // stores the distances of all the nodes from the source 
        map<t,int> dist;
        // initialize those distances to infinity
        for(auto nodePair:l){
            t key=nodePair.first;
            dist[key]=INT_MAX;
        }
        
        // dist of source is 0
        dist[src]=0;
        
        // set will store the elements in increasing order of the distances 
        set<pair<int,t>> set1;
        set1.insert(make_pair(0,src));
        
        while(!set1.empty()){
            
            // take out the front pair of the set 
            auto p = *set1.begin();
            set1.erase(set1.begin());
            
            // find that node's distance and the node itself
            int nodeDist = p.first;
            t node = p.second;
            
            // iterate over the neighbours of the current node
            for(auto neigh:l[node]){
                t neighNode=neigh.first;  // neighbour node itself
                int edge=neigh.second;    // edge len of neighbour from current node 
                
                // check whether the distance from node to neigh is less than that of current dist of neighbour
                if(nodeDist+edge < dist[neighNode]){
                    // if the neighNode already present in set then remove it
                    auto f = set1.find(make_pair(dist[neighNode],neighNode));
                    if(f!=set1.end()){
                        set1.erase(f);
                    }
                    
                    // update the distance and set as well
                    dist[neighNode]=nodeDist+edge;
                    set1.insert(make_pair(dist[neighNode],neighNode));
                }
            }
        }
        
        // printing the distances and the nodes from the map dist 
        for(auto node:dist){
            cout<<node.first<<" at a dist of "<<node.second<<endl;
        }
        
    }
};

int main() {
// 	Graph <int> g;
// 	g.addEdge(1,2,true,1);
// 	g.addEdge(1,4,true,7);
// 	g.addEdge(1,3,true,4);
// 	g.addEdge(2,3,true,1);
// 	g.addEdge(3,4,true,2);
	
// 	g.printAdj();
	
// 	cout<<endl;
	
// 	g.dijkstra(1);


    Graph <string> india;
    india.addEdge("amritsar","delhi",true,1);
    india.addEdge("amritsar","jaipur",true,4);
    india.addEdge("jaipur","delhi",true,2);
    india.addEdge("jaipur","mumbai",true,8);
    india.addEdge("mumbai","bhopal",true,3);
    india.addEdge("bhopal","agra",true,2);
    india.addEdge("agra","delhi",true,1);
    
    india.printAdj();
    cout<<endl;
    india.dijkstra("amritsar");
    
    
	return 0;
}
