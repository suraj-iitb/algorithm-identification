#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
struct edge{int to, cost;};

const int INF = 1e9;
const int MAX = 100000;

int V, E, r;
int dist[MAX];
bool check[MAX];
vector<edge> G[MAX];
void dijkstra(void)
{
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair < int, int > > > pq;

	for (int i = 0; i < V; i++)
	{
		dist[i] = INF;
		check[i] = false;
	}
	pq.push(pair<int, int>(0, r));
	dist[r] = 0;
	while (!pq.empty())
	{
		pair<int, int> p = pq.top(); pq.pop();
		int minv = p.first;
		int u = p.second;
		check[u] = true;
		if (dist[u] < minv) continue;
		rep(i, G[u].size())
		{
			if (check[G[u][i].to]) continue;
			if (dist[G[u][i].to] > dist[u] + G[u][i].cost)
			{
				dist[G[u][i].to] = dist[u] + G[u][i].cost;
				pq.push(pair<int, int>(dist[G[u][i].to], G[u][i].to));
			}
		}
	}
}

signed main(void)
{
	cin >> V >> E >> r;
	rep(i, E)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		G[from].push_back({to, cost});
	}
	dijkstra();
	for (int i = 0; i < V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i]<< endl;
	}
	return 0;
}


