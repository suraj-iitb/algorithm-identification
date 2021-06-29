#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Dijkstra {
	struct Edge {
		const int from;
		const int to;
		const T cost;
		Edge(const int from, const int to, const T cost) :
			from(from),
			to(to),
			cost(cost)
			{}
	};
	const int V;
	vector<vector<Edge>> G;
	int start;
	const int INF = numeric_limits<T>::max();
	vector<T> dist;
	vector<int> rec;
	Dijkstra(const int V) :
		V(V),
		G(vector<vector<Edge>>(V, vector<Edge>()))
		{}
	void addEdge(const int from, const int to, const T cost) {
		assert(cost >= 0);
		G[from].emplace_back(from, to, cost);
	}
	void build(const int start) {
		(*this).start = start;
		dist = vector<T>(V, INF);
		rec = vector<int>(V, -1);
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
		dist[start] = 0;
		que.push({0, start});
		while(que.size()) {
			T cost;
			int from;
			tie(cost, from) = que.top();
			que.pop();
			for(Edge e : G[from]) {
				if(dist[e.from] + e.cost < dist[e.to]) {
					dist[e.to] = dist[e.from] + e.cost;
					rec[e.to] = e.from;
					que.push({dist[e.to], e.to});
				}
			}
		}
	}
	T distance(const int to) {
		if(dist[to] == INF) throw "INVALID";
		return dist[to];
	}
	vector<int> route(int to) {
		distance(to);
		vector<int> ret;
		while(to != start) {
			ret.push_back(to);
			to = rec[to];
		}
		ret.push_back(start);
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main() {
	int V, E, r; cin >> V >> E >> r;
	Dijkstra<int> ds(V);
	while(E--) {
		int s, t, d; cin >> s >> t >> d;
		ds.addEdge(s, t, d);
	}
	ds.build(r);
	for(int to = 0; to < V; ++to) {
		try {
			cout << ds.distance(to) << "\n";
		}
		catch(...) {
			cout << "INF" << "\n";
			continue;
		}
	}
	return 0;
}
