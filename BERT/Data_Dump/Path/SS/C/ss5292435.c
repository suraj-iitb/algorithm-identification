#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
const int MAX_V = 100000, MAX_E = 500000;
const int INF = 0x3f3f3f3f;

vector<pii> G[MAX_V];
void add_edge(int u,int v,int c){
	G[u].push_back(pii(v,c));
}


bool used[MAX_V];
priority_queue<pii> que;
int d[MAX_V];
bool relax(int u,int v,int c){
	if(d[v] > d[u]+c && d[u] != INF){
		d[v] = d[u]+c;
		return true;
	}
	return false;
}
void dijkstra(int s, int V){
	for (int v = 0; v < V; ++v) d[v] = INF;
	d[s] = 0;	
	que.push(pii(-d[s],s));

	while(!que.empty()){
		pii p = que.top();	que.pop();
		int u = p.second, du = -p.first;

		if(used[u] || du > d[u])	continue;
		used[u] = true;

		for (int i = 0; i < G[u].size(); ++i){
			pii p = G[u][i];
			int v = p.first, d_uv = p.second;
			if(relax(u,v,d_uv))
				que.push(pii(-d[v],v));
		}
	}
}

int main(){
	int V,E,r;	scanf("%d%d%d",&V,&E,&r);
	for (int i = 0; i < E; ++i){
		int s,t,d;
		scanf("%d%d%d",&s,&t,&d);
		add_edge(s,t,d);
	}
	dijkstra(r,V);
	for (int v = 0; v < V; ++v){
		if(d[v] == INF)	puts("INF");
		else			printf("%d\n",d[v]);
	}
}


