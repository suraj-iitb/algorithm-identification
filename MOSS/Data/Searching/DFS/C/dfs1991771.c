#include <stdio.h>          // printf(), scanf()
#include <stdbool.h>

#define MAX_V 100

bool g[MAX_V][MAX_V];
bool used[MAX_V];
int d[MAX_V];
int f[MAX_V];
int V;
int t;

void
dfs(int u)
{
	int v;

	used[u] = true;
	d[u] = ++t;
	for (v = 0; v < V; ++v)
	{
		if (g[u][v] && !used[v])
			dfs(v);
	}

	f[u] = ++t;
}

void
solve()
{
	int v;

	t = 0;
	for (v = 0; v < V; ++v)
		used[v] = false;

	for (v = 0; v < V; ++v)
	{
		if (!used[v])
			dfs(v);
	}

	for (v = 0; v < V; ++v)
		printf("%d %d %d\n", v + 1, d[v], f[v]);
}

int
main(int argc, char** argv)
{
	int u, v;
	int k;
	int i, j;

	scanf("%d", &V);
	for (i = 0; i < V; ++i)
	{
		scanf("%d", &u);
		for (v = 1; v <= V; ++v)
			g[u - 1][v - 1] = false;

		scanf("%d", &k);
		for (j = 0; j < k; ++j)
		{
			scanf("%d", &v);
			g[u - 1][v - 1] = true;
		}
	}

	solve();
	return 0;
}
