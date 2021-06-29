#include <bits/stdc++.h>

struct Edge {
	int to;
	int64_t dist{1};

	int64_t cost;
	int64_t capacity;
	int rev_i;
};
using EdgeVec = std::vector<Edge>;
using EdgeLists = std::vector<EdgeVec>;

///////////////////
// ダイクストラ法 //
///////////////////

// 負辺を含まないグラフの最短経路アルゴリズム
// Edgeは{to, dist}
decltype(auto) dijkstra(const EdgeLists& edges, const int source)
{
	using Metric = decltype(Edge::dist);
	std::vector<Metric> distance(edges.size(), std::numeric_limits<Metric>::max());
	using DistPoint = std::pair<Metric, int>;
	std::priority_queue<DistPoint, std::vector<DistPoint>, std::greater<DistPoint>> updatedQueue;
	distance[source] = 0;
	updatedQueue.push({0, source});
	while (!updatedQueue.empty())
	{
		DistPoint now{updatedQueue.top()};
		updatedQueue.pop();
		if (now.first > distance[now.second]) continue;
		for (const Edge& next: edges[now.second])
			if (now.first + next.dist < distance[next.to])
			{
				distance[next.to] = now.first + next.dist;
				updatedQueue.push({distance[next.to], next.to});
			}
	}
	return distance;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
int main()
{
	int V, E, r;
	scanf("%d%d%d", &V, &E, &r);
	EdgeLists edges(V);
	for (int i{}; i < E; i++)
	{
		int s, t, d;
		scanf("%d%d%d", &s, &t, &d);
		edges[s].push_back({t, d});
	}
	auto distance{dijkstra(edges, r)};
	
	constexpr int64_t inf{std::numeric_limits<int64_t>::max()};
	for (int64_t& e: distance)
		if (e == inf)
			puts("INF");
		else
			printf("%lld\n", e);
	return 0;
}
