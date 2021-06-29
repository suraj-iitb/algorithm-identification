#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
vector<vector<pair<int, int>>> G;
void Dij(ll v, vl &dist) {
	dist[v] = 0;
	priority_queue<pl, vector<pl>, greater<pl>> que;
	que.emplace(0, v);
	while (que.size()) {
		ll d = que.top().first, v = que.top().second;
		que.pop();
		for (auto nv : G[v]) {
			if (dist[nv.first] > dist[v] + nv.second) {
				dist[nv.first] = dist[v] + nv.second;
				que.emplace(dist[nv.first], nv.first);
			}
		}
	}
}
int main() {
	int n, e, r;
	scanf("%d%d%d", &n, &e, &r);
	vl dist(n, INF);
	G = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	rep(i, e) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		// a--, b--;
		G[a].push_back({b, c});
		// G[b].push_back({a, c});
	}
	Dij(r, dist);
	for (int i = 0; i < n; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%lld\n", dist[i]);
	}
	return 0;
}
