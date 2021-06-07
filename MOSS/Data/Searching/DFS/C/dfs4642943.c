#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define N 110
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,GMatrices[N][N]={0};
int color[N],d[N],f[N],tt;

void dfs_visit(int u)
{
	int v;
	color[u]=GRAY;
	d[u]=tt+1;
	tt++;
	for(v=0;v<n;v++)
	{
		if(GMatrices[u+1][v+1]==0)
			continue;
		if(color[v]==WHITE)
			dfs_visit(v);
	}
	color[u]=BLACK;
	f[u]=tt+1;
	tt++;
	return;
}
void dfs()
{
	int u;
	for(u=0;u<n;u++)
		color[u]=WHITE;
	tt=0;

	for(u=0;u<n;u++)
		if(color[u]==WHITE)
			dfs_visit(u);

	for(u=0;u<n;u++)
		printf("%d %d %d\n",u+1,d[u],f[u]);
	return;
}
int main()
{
	int u,k,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&u,&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&v);
			GMatrices[u][v]=1;
		}
	}
	
	dfs();

	return 0;
}
