#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	auto dijkstra = [&](const Graph &g, int s, Array &dist) {
		int n = g.size();
		vector<bool> vis(n);
		vector<int> prev(n, -1);
		dist.assign(n, INF);
		dist[s] = 0;
		using State = tuple<Weight, int, int>; // (???????????¢, ???, ???)
		priority_queue<State, vector<State>, greater<State>> pq;
		pq.emplace(0, s, -1);
		while (pq.size()) {
			Weight d; int v, p; tie(d, v, p) = pq.top(); pq.pop();
			if (dist[v] < d)continue;
			vis[v] = true;
			prev[v] = p;
			for (auto &e : g[v]) {
				if (vis[e.d])continue;
				if (dist[e.d] > dist[v] + e.w) {
					dist[e.d] = dist[v] + e.w;
					pq.emplace(dist[e.d], e.d, v);
				}
			}
		}
		return prev;
	};

	int V, E, r; cin >> V >> E >> r;
	Graph g(V);
	rep(i, 0, E) {
		int s, t, d; cin >> s >> t >> d;
		addArc(g, s, t, d);
	}
	Array dist;
	dijkstra(g, r, dist);
	rep(i, 0, V) {
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
	return 0;
}
