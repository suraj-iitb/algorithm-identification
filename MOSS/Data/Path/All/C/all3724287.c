#include <bits/stdc++.h>

int main()
{
	using vi = std::vector<int64_t>;
	using vvi = std::vector<vi>;

	int V, E;
	scanf("%d%d", &V, &E);
	vvi graph(V, vi(V, 1ll << 60));
	for (int i{}; i < V; i++) graph[i][i] = 0;
	for (int i{}; i < E; i++)
	{
		int s, t;
		int64_t d;
		scanf("%d%d%lld", &s, &t, &d);
		graph[s][t] = std::min(graph[s][t], d);
	}
	for (int mid{}; mid < V; mid++)
		for (int from{}; from < V; from++)
			for (int to{}; to < V; to++)
				if (graph[from][mid] < (1ll << 60) && graph[mid][to] < (1ll << 60))
					graph[from][to] = std::min(graph[from][to], graph[from][mid] + graph[mid][to]);
	
	for (int i{}; i < V; i++)
		for (int j{}; j < V; j++)
			if (graph[i][j] + graph[j][i] < 0)
			{
				puts("NEGATIVE CYCLE");
				return 0;
			}
	
	for (int i{}; i < V; i++)
		for (int j{}; j < V; j++)
			if (graph[i][j] == (1ll << 60))
				printf("INF%c", j == V - 1? '\n': ' ');
			else
				printf("%lld%c", graph[i][j], j == V - 1? '\n': ' ');

	return 0;
}
