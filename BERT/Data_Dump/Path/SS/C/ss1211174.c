#include <bits/stdc++.h>

using namespace std;
//static const int INF = 1 << 25; 戒め
static const long long INF = ((long long) 1) << 60;

struct edge
{
	long long to, cost;
	edge(long long t, long long  c){
		to = t;
		cost = c;
	}
};
typedef pair<int, long long> P;

long long  V, E;
vector<edge> G[100000];
long long d[100000];

void dijkstra(int s){
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));
	while(que.size()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main(){
	int r;
	scanf("%d %d %d", &V, &E, &r);
	for(int i = 0; i < E; i++){
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		G[s].push_back(edge(t, d));
	}
	dijkstra(r);
	int ans = 0;
	for(int i = 0; i < V; i++){
		if(d[i] != INF){
			printf("%d\n", d[i]);
		}
		else{
			printf("INF\n");
		}
	}
	return 0;
}
