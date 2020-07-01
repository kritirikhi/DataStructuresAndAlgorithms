//                                                                  Adjacency List using  Unordered Map 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    // unordered map having node data as key (i.e string) and the list of pair<string,int> as thevalue of the key
    // the list conatains the neighbours of the key
    // the graph is a weighted graph so the list conatains the neighbour along with the weight of the edge b/w the neighbour and the key
    unordered_map<string,list<pair<string,int>>> l;
    
    // func to add edge betweenn the nodes
    void addEdge(string x,string y,bool bidirec,int weight){
        l[x].push_back(make_pair(y,weight));
        if(bidirec){
            l[y].push_back(make_pair(x,weight));
        }
    }
    
    // printing the graph
    void printGraph(){
        for(auto pair1:l){  // on iteration,unordered_map gives key value pair
            string city=pair1.first;
            cout<<city<<" => ";
            
            list<pair<string,int>> list1=pair1.second;
            for(auto neigh:list1){
                cout<<neigh.first<<" "<<neigh.second<<",";
            }
            cout<<endl;
        }
    }
    
};

int main() {
	
	Graph g;
	g.addEdge("A","B",true,20);
	g.addEdge("B","D",true,40);
	g.addEdge("A","C",true,10);
	g.addEdge("C","D",true,40);
	g.addEdge("A","D",false,50);
	
	g.printGraph();
	
	return 0;
}