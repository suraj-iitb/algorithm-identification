#include <stdio.h>
#define MAX_N 101
#define START_V 1
#define WILD -1

struct vertex
{
	int N[MAX_N];
	int len_N;
	int d;
} typedef vertex;

vertex V[MAX_N];

void bfs(int);
void reSetDistance(int, int);

int main()
{
	int i, j;
	int n, u;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &u, &V[i].len_N);
		for(j = 1; j <= V[i].len_N; j++)
		{
			scanf("%d", &V[i].N[j]);
		}
	}
	
	bfs(n);
	
	for(i = 1; i <= n; i++)
	{
		printf("%d %d\n", i, V[i].d);
	}
	
	return 0;
}

void bfs(int n)
{
	int i;
	
	for(i = 1; i <= n; i ++)
	{
		V[i].d = WILD;
	}
	
	reSetDistance(START_V, 0);
}

void reSetDistance(int t, int d)
{
	int i;
	int next;
	
	V[t].d = d;
	
	for(i = 1; i <= V[t].len_N; i++)
	{
		next = V[t].N[i];
		
		if(V[next].d == WILD || V[next].d > d + 1)
		reSetDistance(next, d + 1);
	}
}
