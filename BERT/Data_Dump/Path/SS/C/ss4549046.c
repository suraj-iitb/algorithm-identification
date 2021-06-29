/*
	ダイクストラ法(無向グラフ、優先度付きキュー)
												*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1L<<60;
struct edge {
	ll to;
	ll cost;
};
typedef pair<ll, ll> P;

ll V, E;
ll from;
vector<vector<edge> > G;
vector<ll> d;

void dijkstra(ll s){
	priority_queue<P, vector<P>, greater<P> > que;
	for(ll i = 0; i < V; i++) d[i] = INF;
	d[s] = 0;
	que.push(P(0, s));

	while(!que.empty()){
		P p = que.top(); que.pop();
		ll v = p.second;
		if(d[v] < p.first) continue;
		for(ll i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}


int solve() {
	cin >> V >> E;
	if(V == 1) {
		cout << 0 << endl;
		return 0;
	}
	cin >> from;
	d.resize(V);
	G.resize(V);
	for(ll i = 0; i < E; i++) {
		ll a, b, cost;
		cin >> a >> b >> cost;
		edge e = {b, cost};
		G[a].push_back(e);
	}
	dijkstra(from);
	for(ll i = 0; i < V; i++){
		if(d[i] == INF){
			cout << "INF" << endl;
		}else{
			cout << d[i] << endl;
		}
	}
	return 0;
}

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return solve();
}

