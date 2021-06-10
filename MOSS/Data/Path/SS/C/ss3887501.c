#include "bits/stdc++.h"
using namespace std;
using LL=long long;

const int INF = 1'000'000'000;
const long long INFLL = 1'000'000'000'000'000'000;

using Weight=int;
using P=pair<Weight, int>;
struct Edge {
	int to; Weight cost;
	Edge(int _to, Weight _cost) :to(_to), cost(_cost) {}
};
bool operator>(const Edge& e1, const Edge& e2) { return e1.cost > e2.cost; }
struct Edge2 { int u, v; Weight cost; };
using Graph=vector<vector<Edge>>;

void Dijkstra(const Graph& graph, vector<Weight>& dist, int s) {
	int V = graph.size();
	dist.assign(V, INF); dist[s] = 0;

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.emplace(s, 0);

	while (!pq.empty()) {
		Edge p = pq.top(); pq.pop(); int v = p.to;
		if (dist[v] < p.cost)continue;
		for (auto e : graph[v]) {
			if (dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				pq.emplace(e.to, dist[e.to]);
			}
		}
	}
}

int main() {
	int v, e, r; cin >> v >> e >> r;
	Graph g(v);
	for (int i = 0; i < e; i++) {
		int s, t, d; cin >> s >> t >> d;
		g[s].emplace_back(t, d);
	}
	vector<Weight> dist;
	Dijkstra(g, dist, r);
	for (auto aa : dist) {
		if (aa == INF)cout << "INF" << endl;
		else cout << aa << endl;
	}
}
