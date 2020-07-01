#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int,list<int>> l;

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    int bfs(int src ,int dest){
        map<int,int> dist;
        for(auto nodePair:l){
            dist[nodePair.first]=INT_MAX;
        }

        queue<int> q;
        q.push(src);
        dist[src]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto neigh:l[node]){
                if(dist[neigh]==INT_MAX){
                    dist[neigh]=dist[node]+1;
                    q.push(neigh);
                }
            }
        }

        return dist[dest];
    }
};

int main() {
    int t;
    cin>>t;

    for(int q=0;q<t;q++){
        int n,l,s;
        cin>>n>>l>>s;

        int board[n+1]={0};
        for(int i=0;i<l;i++){
            int x,y;
            cin>>x>>y;
            board[x]=y-x;
        }

        for(int i=0;i<s;i++){
            int x,y;
            cin>>x>>y;
            board[y]=-(y-x);
        }

        Graph g;

        for(int i=0;i<=n;i++){
            for(int dice=1;dice<=6;dice++){
                int j=i+dice;
                j=j+board[j];
                g.addEdge(i,j);
            }
        }
        cout<<g.bfs(1,n);
        cout<<endl;
    }
}