#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
        int V;
        unordered_map<int,list<pair<int,int>>> mp;
        
        graph(int V){
            this->V = V;
        }
        
        void addEdge(int x,int y,int w){
            mp[x].push_back(make_pair(y,w));
            mp[y].push_back(make_pair(x,w));
        }
        
        void print(){
            for(auto nodePair:mp){
                cout<<nodePair.first<<" => ";
                for(auto x:nodePair.second){
                    int node = x.first;
                    int wt = x.second;
                    cout<<"{"<<node<<","<<wt<<"}"<<" ";
                }
                cout<<endl;
            }
        }
        
        void prims(int src){
            int visited[V+1]={0};
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
            
            minheap.push(make_pair(0,src));
            
            int mst=0;
            while(!minheap.empty()){
                pair<int,int> node = minheap.top();
                minheap.pop();
                
                if(visited[node.second]==1){
                    continue;
                }
                
                mst+=node.first;
                
                visited[node.second]=1;
                
                for(auto neigh:mp[node.second]){
                    if(visited[neigh.first]==0){
                        minheap.push(make_pair(neigh.second,neigh.first));
                    }
                }
            }
            cout<<mst;
        }
};

int main() {
	
	int n,m;
	cin>>n>>m;
	
	graph g(n);
	
	for(int i=0;i<m;i++){
	    int x,y,w;
	    cin>>x>>y>>w;
	    g.addEdge(x,y,w);
	}
	
	g.print();
	g.prims(1);
	
	return 0;
}
