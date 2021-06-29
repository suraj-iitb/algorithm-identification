#include <stdio.h>

typedef struct
{
	int k, v[100];
	int d, f;
	int visited;
} Node;

int dfs(Node *node, int u, int t)
{
	if(node[u].visited == 0)
	{
		node[u].visited = 1;
		
		node[u].d = ++t;
		for(int i = 0; i < node[u].k; ++i)
		{
			t = dfs(node, node[u].v[i], t);
		}
		node[u].f = ++t;
	}
	return t;
}

int main()
{
	int n, u;
	Node node[100];
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &u);
		--u;
		
		scanf("%d", &node[u].k);
		for(int j = 0; j < node[u].k; ++j)
		{
			scanf("%d", &node[u].v[j]);
			--node[u].v[j];
		}
		node[u].visited = 0;
	}
	
	for(int i = 0, t = 0; i < n; ++i)
	{
		t = dfs(node, i, t);
	}
	
	for(int i = 0; i < n; ++i)
	{
		printf("%d %d %d\n", i+1, node[i].d, node[i].f);
	}
}

