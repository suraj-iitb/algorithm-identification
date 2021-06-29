#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

//BEGIN
template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T> > > G) {
	const T INF = numeric_limits<T>::max();
	const int N = G.size();
	vector<T> cost(N, INF);
	vector<int> prevr(N, -1); //経路復元用
	priority_queue < pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > pq;
	cost[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		pair<T, int> p = pq.top(); pq.pop();
		int now = p.second;
		if (cost[now] < p.first) continue;
		for (auto next : G[now]) {
			int nv = next.first, nw = next.second;
			if (cost[nv] > cost[now] + nw) {
				cost[nv] = cost[now] + nw;
				prevr[nv] = now;
				pq.push(make_pair(cost[nv], nv));
			}
		}
	}
	return cost;
}

vector<int> get_path(int t, vector<int> preve) {
	vector<int> path;
	for (; t != -1; t = preve[t]) path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}
//END

int main() {
	int V, E, r; cin >> V >> E >> r;
	vector<vector<pair<int, int> > > G(V);
	for (int i = 0; i < E; ++i) {
		int s, t, d; cin >> s >> t >> d;
		G[s].push_back(make_pair(t, d));
	}
	vector<int> ans = dijkstra(r, G);
	for (int i = 0; i < V; ++i) {
		if (ans[i] == numeric_limits<int>::max()) cout << "INF" << endl;
		else cout << ans[i] << endl;
	}

	return 0;
}


/*
	created: 2019-08-26
	https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
*/
