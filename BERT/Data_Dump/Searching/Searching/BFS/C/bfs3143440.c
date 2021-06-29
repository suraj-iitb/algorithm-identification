#include <stdio.h>

typedef struct
{
	int k, v[100];
	int visited;
} Node;

int queue_head = 0;
int queue_tail = 0;
int queue_data[100];

void queue_push(int x)
{
	queue_data[queue_tail++] = x;
	queue_tail %= 100;
}

int queue_pop(void)
{
	int x = queue_data[queue_head++];
	queue_head %= 100;
	return x;
}

int queue_empty(void)
{
	return queue_head == queue_tail;
}

void bfs(Node *node, int u)
{
	queue_push(u);
	node[u].visited = 0;
	
	while(!queue_empty())
	{
		int x = queue_pop();
		for(int i = 0; i < node[x].k; ++i)
		{
			int v = node[x].v[i];
			if(node[v].visited == -1)
			{
				queue_push(v);
				node[v].visited = node[x].visited + 1;
			}
		}
	}
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
		node[u].visited = -1;
	}
	
	bfs(node, 0);
	
	for(int i = 0; i < n; ++i)
	{
		printf("%d %d\n", i+1, node[i].visited);
	}
}

