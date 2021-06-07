#include <stdio.h>          // printf(), scanf()
#include <stdlib.h>         // exit()
#include <stdbool.h>

#define MAX_V 100
#define INF -1
#define QUE_SIZE 100

bool g[MAX_V][MAX_V];
int d[MAX_V];
int V;

int queue[QUE_SIZE];
int que_in;
int que_out;

void
cleanup(int ecode)
{
	exit(ecode);
}

int
que_size()
{
	if (que_in >= que_out)
		return que_in - que_out;

	return que_in + QUE_SIZE - que_out;
}

void
que_push(int x)
{
	queue[que_in] = x;
	que_in = (que_in + 1) % QUE_SIZE;
	if (que_in == que_out)
	{
		fprintf(stderr, "Queue overflow. size:%d\n", QUE_SIZE);
		cleanup(1);
	}
}

void
que_pop()
{
	if (que_out == que_in)
	{
		fprintf(stderr, "Queue underflow\n");
		cleanup(1);
	}

	que_out = (que_out + 1) % QUE_SIZE;
}

int
que_front()
{
	return queue[que_out];
}

void
solve()
{
	int u, v;

	for (u = 0; u < V; ++u)
		d[u] = INF;

	d[0] = 0;
	que_push(0);	
	while (que_size() >= 1)
	{
		u = que_front(); que_pop();
		for (v = 0; v < V; ++v)
		{
			if (g[u][v] && d[v] == INF)
			{
				d[v] = d[u] + 1;
				que_push(v);
			}
		}
	}

	for (u = 0; u < V; ++u)
		printf("%d %d\n", u + 1, d[u]);
}

int
main(int argc, char** argv)
{
	int u, v;
	int k;
	int i, j;

	que_in = 0;
	que_out = 0;

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
