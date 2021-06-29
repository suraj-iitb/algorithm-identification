#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;
typedef std::pair<LL, LL> P;

const LL inf = 1123456789012;

struct edge { LL to, cost; };
std::vector<std::vector<edge>>G;
std::vector<LL>dist;
void dijkstra(LL r)
{
	std::fill(dist.begin(), dist.end(), inf);
	dist[r] = 0;
	std::priority_queue<P, std::vector<P>, std::greater<P>>queue;
	queue.push(P(0, r));
	while (!queue.empty())
	{
		auto p = queue.top(); queue.pop();
		LL cost = p.first, v = p.second;
		if (dist[v] < cost) continue;
		for (auto e : G[v])
		{
			if (dist[e.to] > dist[v] + e.cost)
			{
				dist[e.to] = dist[v] + e.cost;
				queue.push(P(dist[e.to], e.to));
			}
		}
	}
}

int main()
{
	LL V, E, r;
	in >> V >> E >> r;
	std::vector<LL>s(E), t(E), d(E);
	rep(i, E) in >> s[i] >> t[i] >> d[i];

	G.resize(V); dist.resize(V);
	rep(i, E) G[s[i]].push_back({ t[i], d[i] });
	dijkstra(r);

	rep(i, V)
	{
		if (dist[i] >= inf) out << "INF" << std::endl;
		else out << dist[i] << std::endl;
	}
}

