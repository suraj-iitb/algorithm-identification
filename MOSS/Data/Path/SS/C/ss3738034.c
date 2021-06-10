#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_V = 100000;
const ll INF = ll(1e16);

int V, E;
struct edge { int to;ll cost; };
typedef pair<int, int>P;
int N;
vector<edge>G[MAX_V];
ll d[MAX_V];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
int main()
{
	cin >> V >> E;
	int r;
	cin >> r;
	for (int i = 0; i < E; i++)
	{
		int s, t;
		ll d;
		cin >> s >> t >> d;
		G[s].push_back({t,d});
	}
	dijkstra(r);

	//出力
	for (int i = 0; i < V; i++)
	{
		if (d[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << d[i] << endl;
		}
	}
	return 0;
}
