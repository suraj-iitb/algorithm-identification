#include "bits/stdc++.h"
using namespace std;

#define int long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

// 重み付きグラフ
// できてほしいこと
// DFS, BFS, bellman-ford, サイクル検出、トポロジカルソートなど
struct Graph {
	struct Edge {
		int to;
		int weight;
	};
	vector<vector<Edge>> g;

	//------------
	// 初期化
	Graph(int N) { g.assign(N, vector<Edge>()); }

	//------------
	// 辺追加
	Edge add(int from, int to, int weight = 1) {
		Edge e = { to, weight };
		g[from].push_back(e);
		return e;
	}

	//------------
	// 深さ優先探索（startからの全点への距離を返す）
	vector<int> dfs(int start) {
		vector<int> dist(g.size(), INF);
		vector<int> seen(g.size(), false);

		stack<int> s;
		s.push(start);
		seen[start] = true;

		while (!s.empty()) {
			int u = s.top(); s.pop();
			for (Edge e : g[u]) {
				if (seen[e.to]) continue;
				else {
					dist[e.to] = min(dist[e.to], dist[u] + e.weight);
					s.push(e.to);
					seen[e.to] = true;
				}
			}
		}
		return dist;
	}

	//------------
	// 深さ優先探索（再帰バージョン）（startからの全点への距離を返す）
	void dfs2_internal(int v, vector<int>& seen, vector<int>& dist) {
		seen[v] = true;
		for (Edge e : g[v]) {
			if (seen[e.to]) continue;
			else {
				dist[e.to] = min(dist[e.to], dist[v] + e.weight);
				dfs2_internal(e.to, seen, dist);
				seen[e.to] = true;
			}
		}
	}
	vector<int> dfs2(int start) {
		vector<int> dist(g.size(), INF);
		vector<int> seen(g.size(), false);
		dist[start] = 0;
		dfs2_internal(start, seen, dist);

		return dist;
	}

	//------------
	// Dijkstra法（蟻本）
	// 到達できない頂点はINFを返す
	vector<int> dijkstra(int start) {
		vector<int> dist(g.size(), INF);
		priority_queue<P, vector<P>, greater<P>> q;

		dist[start] = 0;
		q.push({ 0,start });
		while (!q.empty()) {
			int d, v;
			tie(d, v) = q.top(); q.pop();
			if (dist[v] < d) continue;  // 枝刈り
			for (Edge e : g[v]) {
				if (dist[e.to] <= dist[v] + e.weight) continue; // 枝刈り
				dist[e.to] = dist[v] + e.weight;
				q.push({ dist[e.to], e.to });
			}
		}
		return dist;
	}

	//------------
	// Bellman-Ford
	// 到達できない頂点はINFを返す
	// 負サイクルがあればnegative_cycle=trueを返す
	pair<vector<int>, bool> BellmanFord(int start) {
		vector<int> dist(g.size(), INF);
		int N = g.size();

		dist[start] = 0;

		bool negative_cycle = false;

		for (int i = 0; i < N; i++) {
			for (int v = 0; v < N; v++) {
				for (Edge e : g[v]) {

					if (dist[v] != INF && dist[e.to] > dist[v] + e.weight) {
						dist[e.to] = dist[v] + e.weight;
						// N回目にも更新があれば負サイクルあり
						if (i == N - 1) {
							dist[e.to] = -INF;
							negative_cycle = true;
						}
					}
				}
			}
		}
		return { dist, negative_cycle };
	}
	//------------
	// Warshall-Floyd法
	// 到達できない頂点はINFを返す
	vector<vector<int> > WarshallFloyd() {
		int N = g.size();
		vector<vector<int>> d(N, vector<int>(N, INF));
		rep(i, N) d[i][i] = 0;
		rep(i, N)for (auto e : g[i]) {
			d[i][e.to] = e.weight;
		}

		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				if (d[i][k] == INF) continue;
				for (int j = 0; j < N; j++) {
					if (d[k][j] == INF) continue;
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		return d;
	}
};


signed main() {

	int N, M;
	cin >> N >> M ;
	Graph g(N);
	rep(i, M) {
		int s, t, d;
		cin >> s >> t >> d;
		g.add(s, t, d);
	}
	vector<vector<int>> result;
	result = g.WarshallFloyd();

	bool negative_cycle = false;
	rep(i, N) {
		if (result[i][i] < 0) negative_cycle = true;
	}

	if (negative_cycle)
		cout << "NEGATIVE CYCLE" << endl;
	else {
		rep(i, N) {
			rep(j, N) {
				if (result[i][j] == INF) cout << "INF";
				else cout << result[i][j];
				if (j != N - 1) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

