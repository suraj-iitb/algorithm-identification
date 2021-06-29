#include "bits/stdc++.h"
using namespace std;

// コンテスト中のみ
//#define int long long

#define ll long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define P pair<ll,ll>
int MOD = 1000000007;
const int inf = 1001001001;
const ll INF = 1LL << 60;

int v, e;
vector<P>edge[1000010];

vector<ll>dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>>pq;
	vector<ll>dist(v, INF);
	dist[s] = 0;
	pq.push({ dist[s],s });
	while (!pq.empty()) {
		P p = pq.top(); pq.pop();
		int from = p.second; ll d = p.first;
		if (dist[from] < d)continue;
		for (auto nv : edge[from]) {
			int to = nv.first; ll c = nv.second;
			if (dist[from] + c < dist[to]) {
				dist[to] = dist[from] + c;
				pq.push({ dist[to],to });
			}
		}
	}
	return dist;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> v >> e;
	int r; cin >> r;
	rep(i, e) {
		int s, t; ll d; cin >> s >> t >> d;
		edge[s].push_back({ t,d });
	}
	auto d = dijkstra(r);
	rep(i, v) {
		if (d[i] == INF)cout << "INF" << endl;
		else cout << d[i] << endl;
	}
	return 0;
}
