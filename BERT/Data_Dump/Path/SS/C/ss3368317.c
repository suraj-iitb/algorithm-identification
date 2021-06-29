#include "bits/stdc++.h"
using namespace std;
#define INF (1LL << 60)

typedef long long ll;
struct edge { ll to, cost; };
typedef pair<ll, ll> P;   // firstは最短距離、secondは頂点の番号

const ll MAX_V = 110000, MAX_E = 510000;

ll V, E;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
	// greater<P>を指定することでfirstが小さい順に取り出せるようにする
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + V, INF);
	// 始点 s の距離は０
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		// PQ内にあるものの中で最も距離の短いものを取り出す
		P p = que.top(); que.pop();
		ll v = p.second;
		if (d[v] < p.first) continue;
		// 頂点 v と隣接している頂点を調べる
		for (ll i = 0; i<G[v].size(); i++) {
			edge e = G[v][i];
			// この時点での頂点 e.to への最短距離より頂点 v を経由して頂点 e.to に行く経路の方が短いとき最短距離を更新する
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
int main() {
	ll r;
	cin >> V >> E >> r;
	for (ll i = 0; i < E; i++) {
		ll s, t, cost;
		cin >> s >> t >> cost;
		G[s].push_back(edge{ t, cost });
	}

	dijkstra(r);
	
	for (ll i = 0; i < V; i++) {
		if(d[i]==INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}
}

