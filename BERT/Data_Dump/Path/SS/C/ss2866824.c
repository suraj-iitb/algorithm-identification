#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18+9;

class Edge{
public:
	long long cost;
	int from, to;
	Edge(long long c, int f, int t){
		cost = c;
		from = f;
		to = t;
	}
};

bool operator < (const Edge &e, const Edge &f){
	return e.cost != f.cost ? e.cost > f.cost : e.from != f.from ? e.from < f.from : e.to < f.to;
}

typedef vector<vector<Edge> > Graph;

void readGraph(Graph &g, int E, bool D, bool C){ // E:NumofEdges, D:Directed, C:Costed
	for(int i=0; i<E; ++i){
		Edge e(0, 0, 0);
		if(!C) cin >> e.from >> e.to;
		else cin >> e.from >> e.to >> e.cost;
//		--e.from;
//		--e.to;
		g[e.from].push_back(e);
		if(!D){
			swap(e.from, e.to);
			g[e.from].push_back(e);
		}
	}
}

void dijkstra(int s, const Graph &g, vector<long long> &dist){
	int V = g.size();
	dist = vector<long long>(V, INF);
	dist[s] = 0;
	priority_queue<Edge> q;
	q.push(Edge(0, s, s));
	while(!q.empty()){
		Edge e = q.top();
		q.pop();
		if(dist[e.to] < e.cost) continue;
		for(int i=0; i<(int)g[e.to].size(); ++i){
			Edge f = g[e.to][i];
			if(dist[f.to] > dist[e.to] + f.cost){
				dist[f.to] = dist[e.to] + f.cost;
				q.push(Edge(dist[f.to], s, f.to));
			}
		}
	}
}

int main(){
	int v, e, r;
	cin >> v >> e >> r;
	Graph g(v);
	readGraph(g, e, true, true);
	vector<long long> d(v);
	dijkstra(r, g, d);
	for(auto i : d){
		if(i == INF) cout << "INF" << endl;
		else cout << i << endl;
	}
}
