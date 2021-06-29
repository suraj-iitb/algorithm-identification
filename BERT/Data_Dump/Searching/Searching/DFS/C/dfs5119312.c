#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100

int n,G[N][N],color[N],d[N],f[N],time=0;

void dfs_visit(int u)
{
	int v;
	
	
	color[u] = GRAY;
	d[u] = ++time;
	
	for(v=0;v<n;v++)
	{
		if(G[u][v]==0)
		{
			continue;
		}
		if(color[v]==WHITE)
		{
			dfs_visit(v);
		}
	}
	
	color[u] = BLACK;
	f[u] = ++time;
}

void dfs()
{
	int u;
	for(u=0;u<n;u++)
	{
		color[u]=WHITE;
	}
	time = 0;
	for(u=0;u<n;u++)
	{
		if(color[u]==WHITE)
		{
			dfs_visit(u);
		}
	}
}


int main(void)
{
	int i,j,a,b,c;
	
	a = 0;
	b = 0;
	c = 0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			G[i][j] = 0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=0;j<b;j++)
		{
			scanf("%d",&c);
			G[a-1][c-1] = 1;
		}
	}
	
	dfs();
	
	for(i=0;i<n;i++)
	{
		 printf("%d %d %d\n", i+1, d[i], f[i]);
	}
	
	return 0;
}
