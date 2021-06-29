#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define V_MAX 100005
#define INF 1e10
typedef long long ll;
typedef pair<int, ll> P; // 点と、そこへの始点からの最短距離

struct edge {
	int to;
	ll cost;
};

int main(){
	ll nv,ne,r;
	cin >> nv>>ne>>r;

	vector<edge> G[V_MAX];

	rep(i, ne) {
		int s,t;
		ll w;
		cin >> s>>t>>w;
		G[s].push_back({t,w});	// 構造体は{}で表せる
	}

	// 始点からの最短距離を格納
	ll d[V_MAX];
	rep(i, V_MAX) {
		d[i] = INF;
	}
	d[r] = 0;

 	// priority_queue<P, vector<P>, greater<P>> Q;
 	queue<P> Q;

 	Q.push(P(r, 0));

 	while(!Q.empty()) {
 		// P p = Q.top(); Q.pop();
 		P p = Q.front(); Q.pop();
 		int vertex = p.first;
 		ll cost = p.second;
 		if (d[vertex] < cost) {
 			// out of date
 			continue;
 		}
 		rep(i, (int)G[vertex].size()) {
 			edge e = G[vertex][i];
 			// 周辺点について、更新できるようならしていく
 			if (d[e.to] > d[vertex] + e.cost) {
 				d[e.to] = d[vertex] + e.cost;
 				Q.push(P(e.to, d[e.to]));
 			}
 		}
 	}

 	rep(i, nv) {
 		if (d[i]==INF) {
 			cout << "INF" << endl;
 		} else {
 			cout << d[i] << endl;
 		}
 	}
}
