#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class dsu{
 public:
    int n;
    vector<int> par;
    vector<int> sz;  // part of ques pairing
    int totalComp;
    
    dsu(int V){
        n=V;
        par.resize(n);
        sz.resize(n);
        totalComp=n;
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
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
            // part of ques pairing
            sz[superPary]+=sz[superParx];
            sz[superParx]=0;
        }
        totalComp--;
    }
};

int main() {
	int n,m;
	cin>>n>>m;
	
	dsu g(n);
	for(int q=0;q<m;q++){
	    int x,y;
	    cin>>x>>y;
	    g.unite(x,y);
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
	    int superPari=g.getSuperPar(i);
	    ans += n-g.sz[superPari];
	}
	
	cout<<ans/2;
	return 0;
}
