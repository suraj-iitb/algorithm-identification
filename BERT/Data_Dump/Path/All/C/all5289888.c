#include <bits/stdc++.h>
using namespace std;

struct edge{
	long long to;
	long long cost;
};
bool operator<(const edge &a, const edge &b){
	return a.cost==b.cost ? a.to<b.to : a.cost<b.cost;
}

vector<vector<long long> > warshall_floyd(vector<vector<edge> > g){
	// if there is a negative cycle, some of d[i][i]<0
	long long n=g.size(),i,j,k,inf=2000000000000000000;
	vector<vector<long long> > d(n,vector<long long>(n,inf));
	
	for(i=0; i<n; i++){
		d[i][i]=0;
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<g[i].size(); j++){
			d[i][g[i][j].to]=g[i][j].cost;
		}
	}
	
	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(d[i][k]<inf && d[k][j]<inf){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
	}
	
	return d;
}

int main() {
	long long n,m,i,j,u,v,l,jud,inf=2000000000000000000;
	cin >> n >> m;
	vector<vector<edge> > g(n,vector<edge>(0));
	edge e;
	for(i=0; i<m; i++){
		cin >> u >> v >> l;
		e.to=v; e.cost=l;
		g[u].push_back(e);
	}
	
	vector<vector<long long> > d=warshall_floyd(g);
	jud=1;
	for(i=0; i<n; i++){
		if(d[i][i]<0){
			jud=0;
		}
	}
	if(jud==0){
		cout << "NEGATIVE CYCLE" << endl;
	}else{
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(j>0){
					cout << ' ';
				}
				if(d[i][j]==inf){
					cout << "INF";
				}else{
					cout << d[i][j];
				}
			}
			cout << endl;
		}
	}
	
	return 0;
}
