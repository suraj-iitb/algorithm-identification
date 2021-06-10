#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<time.h>
#include<tuple>
#include<utility>
#include<vector>

using namespace std;
long gcd(long x, long y) { if (x > y) { return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; } return x; }
long lcm(long x, long y) { return (x / gcd(x, y) * y); }

using pll = pair<long, long>;
using W_graph = vector<vector<pll>>;

vector<long> dijkstra(W_graph g, long s) {
	vector<long> dist(g.size(), INT_MAX);
	priority_queue<pll, vector<pll>, greater<pll>> Q;
	dist[s] = 0;
	Q.push(make_pair(dist[s], s));

	while (!Q.empty()) {
		long cost, now;
		tie(cost, now) = Q.top(); Q.pop();

		for (auto e : g[now]) {
			long path, next;
			tie(next, path) = e;
			if (cost + path >= dist[next]) continue;
			dist[next] = cost + path;
			Q.push(make_pair(dist[next], next));
		}
	}
	return dist;
}

int main() {
	long N, M ,r; cin >> N >> M >> r;
	W_graph g(N);

	for (int i = 0; i < M; i++) {
		long a, b, c; cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		//g[b].push_back(make_pair(a, c));
	}

	vector<long> res = dijkstra(g, r);

	for (int i = 0; i < N; i++) if (res[i] != INT_MAX) cout << res[i] << endl; else cout << "INF" << endl;
}
