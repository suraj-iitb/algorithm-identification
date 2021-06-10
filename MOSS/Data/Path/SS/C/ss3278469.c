#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const i64 INF = 1LL << 50;

template<typename T> struct Edge {
	int to;
	T cost;
};

template<typename T> class WeightedGraph {
	vector<vector<Edge<T> > > data;
public:
	WeightedGraph(int size) {
		data.resize(size);
	}
	
	inline vector<Edge<T> > operator[](int index) const { return data[index]; }
	inline vector<Edge<T> >& operator[](int index) { return data[index]; }
	
	size_t size() {
		return data.size();
	}
};

template<typename T> vector<T> dijkstra(WeightedGraph<T> &g, int s) {
	vector<T> dist(g.size(), INF); 
	priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > q;
	
	dist[s] = 0;
	q.push({0, s});
	
	while (!q.empty()) {
		pair<T, int> p = q.top(); q.pop();
		int v = p.second;
		if (dist[v] < p.first) continue;
		for (int i = 0; i < g[v].size(); i++) {
			Edge<T> e = g[v][i];
			if (dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				q.push({dist[e.to], e.to});
			}
		}
	}
	
	return dist;
}

int main(void) {
  int v, e, r;
  cin >> v >> e >> r;
  WeightedGraph<i64> g(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    g[s].push_back({t, d});
  }
  vector<i64> dists = dijkstra(g, r);
  for (int i = 0; i < v; i++) {
    if (dists[i] < INF) cout << dists[i] << endl;
    else cout << "INF" << endl;
  }
}

