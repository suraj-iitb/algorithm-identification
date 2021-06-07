#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n, m[N][N];
int col[N], x[N], y[N], t;

void dfs_vst(int i)
{
	int v;
	col[i] = G;
	x[i] = ++t;
	for(v = 0; v < n; v++)
	{
		if(m[i][v] == 0) continue;
		if(col[v] == W)
		{
			dfs_vst(v);
		}
	}	
	col[i] = B;
	y[i] = ++t;
} 

void dfs()
{
	for(int i = 0; i < n; i++)
		col[i] == W;
	
	for(int i = 0; i < n; i++)
	{
		if(col[i] == W) dfs_vst(i);
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d %d %d\n", i+1, x[i], y[i]);
	}
}

int main()
{
	int p, q, r;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			m[i][j] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &p, &r);
		p--;
		for(int j = 0; j < r; j++)
		{
			scanf("%d", &q);
			q--;
			m[p][q] = 1;
		}
	}
	dfs();
	return 0;
}
