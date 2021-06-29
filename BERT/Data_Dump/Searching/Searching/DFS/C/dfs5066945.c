#include<stdio.h>
#define N 100
int G[N][N];
int d[N];
int f[N];
int f2[N];
int t=0;

void re_visit(int u,int n)
{
	int i;
	f2[u]=1;
	d[u]=++t;
	
	for(i=0;i<n;i++)
	{
		if(G[u][i] && d[i]==0)
		{
			re_visit(i,n);
		}
	}
	f[u]=++t;
	
	return;
}

int main(void)
{
	int n,u,i,j,k,v;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		f2[i]=0;
		for(j=0;j<n;j++)
		{
			G[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&v);
			G[u-1][v-1]=1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(d[i]==0)
		{
			re_visit(i,n);
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
	
	return 0;
}
