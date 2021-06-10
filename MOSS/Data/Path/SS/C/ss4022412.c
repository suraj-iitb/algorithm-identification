#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
ll INF = 1e15;
struct Edge {
	ll to;
	ll cost;
};
using P = pair<ll, ll>;
vector<Edge>G[100005];
ll d[100005];

int main() {
	int r;
	int V;
	int E;
	cin >> V >> E >> r;
	for (int i = 0; i < E; i++) {
		ll s, t, d;
		cin >> s >> t >> d;
		G[s].push_back(Edge{t,d});
	}
	
	priority_queue<P, vector<P>, greater<P>>que;
	
	for (int i = 0; i < V; i++) {
		d[i] = INF;
	}
	d[r] = 0;
	que.push(P(0, r));
	while (que.size()) {
		P p = que.top(); que.pop();
		ll cost = p.first;
		int v = p.second;
		if (d[v] < cost) continue;
		for (int i = 0; i < G[v].size(); i++) {
			Edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (d[i] == 1e15) {
			cout << "INF" << endl;
		}
		else {
			cout << d[i] << endl;
		}
	}
	return 0;
}
