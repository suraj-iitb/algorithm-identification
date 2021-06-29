#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1ll<<60;
struct grid{ll to; ll cost;};

using Graph = vector<vector<grid>>;
using P = pair<ll, ll>;

int main(int argc, char **argv)
{
	ll V, E, start; cin >> V >> E >> start;

	Graph G(V);
	for (ll i = 0; i < E; ++i)
	{
		ll s, t, d; cin >> s >> t >> d;
		G[s].push_back(grid{t, d});
	}

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, start));
	vector<ll> dist(V, INF);
	dist[start] = 0;

	while (!que.empty())
	{
		P p = que.top(); que.pop();
		ll now = p.second;
		if (dist[now] < p.first) continue;

		for (auto &nv : G[now])
		{
			if (dist[nv.to] > dist[now] + nv.cost)
			{
				dist[nv.to] = dist[now] + nv.cost;
				que.push(P(dist[nv.to], nv.to));
			}
		}
			
	}
	for (auto &nv : dist)
	{
		if (nv == INF)
			std::cout << "INF" << std::endl;
		else
			std::cout << nv << std::endl;
	}
}
