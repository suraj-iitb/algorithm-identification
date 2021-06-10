#include<bits/stdc++.h>
using namespace std;


struct Edge {
	int to;
	int weight;
};

vector<long long> dijkstra(vector<vector<Edge>>& G, int s) {
	const long long INF = 1LL << 61;
	using P = pair<int, int>;

	vector<long long> dist(G.size(), INF);
	dist[s] = 0;
	priority_queue<P, vector<P>, greater<P>> Q;	
	Q.emplace(0, s);
	while (!Q.empty()) {
		int cost, v;
		tie(cost, v) = Q.top();
		Q.pop();
		for (auto e : G[v]) {
			if (dist[v] + e.weight < dist[e.to]) {
				dist[e.to] = dist[v] + e.weight;
				Q.emplace(dist[e.to], e.to);
			}
		}
	}
	return dist;
}


vector<vector<Edge>> g(500005);

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	for (int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		g[s].push_back({t, d});
	}

	const long long INF = 1LL << 61;
	vector<long long> dist = dijkstra(g, r);

	for (int i = 0; i < V; i++) {
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}

	return 0;
}
