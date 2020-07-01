// Use List class from STL
// for a given vertex we will make array of list coz the vertex is from (0 to N-1) 
// for ith vertex, all the neighbours of ith vertex will be in the form of list
// for eg :- 
//      the the vertex 2 has 5,6 as its neighbours it will be represented in the array as
        // 0 => 
        // 1 =>
        // 2 => 5 ,6
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// defining Graph as user defined data type
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
        l[y].push_back(x);
    }
    
    
    // func to print the graph
    void printGraph(){
        for(int i=0;i<V;i++){
            cout<<"vertex "<<i<<" => ";
            for(auto vertex:l[i]){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
 
    g.printGraph();
	return 0;
}
