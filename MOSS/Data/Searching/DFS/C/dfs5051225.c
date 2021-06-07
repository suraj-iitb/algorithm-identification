#include <stdio.h>

int n,A[100][100],color[100],d[100],f[100],t;


void dfs(int u)
{
	
	int v;
	color[u]=1;
	d[u]=++t;

	for(v=0;v<n;v++)
	{
		if(A[u][v]==0)
		{
			continue;
		}

		if(color[v]==0)
		{
			dfs(v);
		
		}
	}
	
	color[u]=2;
	f[u]=++t;
}





int main (void)
{
	int i,j,k,u,v;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j]=0;
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&u,&k);
	
		
		for(j=0;j<k;j++)
		{
			scanf("%d",&v);
			A[u-1][v-1]=1;
		}
		
	}
	
	

	for(i=0;i<n;i++)
	{
		color[i]=0;
	}
	t=0;

	for(i=0;i<n;i++)
	{
		if(color[i]==0)
		{
			dfs(i);
		}
	}

	for(i=0;i<n;i++)
	{
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
	
}

