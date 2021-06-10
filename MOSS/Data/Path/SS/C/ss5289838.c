#include <bits/stdc++.h>
using namespace std;

struct edge{
	long long to;
	long long cost;
};
bool operator<(const edge &a, const edge &b){
	return a.cost==b.cost ? a.to<b.to : a.cost<b.cost;
}
vector<long long> dijkstra(vector<vector<edge> > g, long long r){
	// input graph g, vertexs are 0-indexed, do not include parallel edges
	// r is source
	// inf=2e18;
	long long n=g.size(),inf=2000000000000000000,u,v,i,j;
	vector<long long> d(n,inf);
	d[r]=0;
	set<pair<long long,long long> > s;
	pair<long long,long long> p;
	set<pair<long long,long long> >::iterator itr=s.begin();
	for(i=0; i<n; i++){
		p.first=d[i]; p.second=i;
		s.insert(p);
	}
	while(!s.empty()){
		itr=s.begin();
		p=*itr;
		s.erase(p);
		u=p.second;
		for(j=0; j<g[u].size(); j++){
			v=g[u][j].to;
			if(d[u]+g[u][j].cost<d[v]){
				s.erase({d[v],v});
				d[v]=d[u]+g[u][j].cost;
				s.insert({d[v],v});
			}
		}
	}
	return d;
}

int main() {
	long long n,m,i,u,v,l,r,inf=2000000000000000000;
	cin >> n >> m >> r;
	vector<vector<edge> > g(n,vector<edge>(0));
	edge e;
	for(i=0; i<m; i++){
		cin >> u >> v >> l;
		e.to=v; e.cost=l;
		g[u].push_back(e);
	}
	vector<long long> d=dijkstra(g,r);
	for(i=0; i<n; i++){
		if(d[i]==inf){
			cout << "INF" << endl;
		}else{
			cout << d[i] << endl;
		}
	}
	return 0;
}
