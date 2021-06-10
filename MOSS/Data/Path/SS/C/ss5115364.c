#include <bits/stdc++.h>

using namespace std;

struct Edge {
    long to;
    long w;
};

using Graph = vector<vector<Edge>>;
const long INF = 10000 * (100000 - 1) + 1;

int main()
{
    long V, E, r;
    cin >> V >> E >> r;

    Graph g;
    g.resize(V);

    for (long i = 0; i < E; i++) {
	long u, v, w;
	cin >> u >> v >> w;
	g[u].push_back({v, w});
    }

    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    vector<long> dist(V, INF);
    pq.push(make_pair(r, 0));
    dist[r] = 0;

    while (!pq.empty()) {
	long u = pq.top().first;
	long d = pq.top().second;
	pq.pop();
	if (dist[u] < d) continue;
	for (Edge e : g[u]) {
	    long v = e.to;
	    if (dist[u] + e.w < dist[v]) {
		dist[v] = dist[u] + e.w;
		pq.push(make_pair(v, dist[v]));
	    }
	}
    }

    for (long u = 0; u < V; u++) {
	if (dist[u] == INF) cout << "INF";
	else cout << dist[u];
	cout << endl;
    }

}

