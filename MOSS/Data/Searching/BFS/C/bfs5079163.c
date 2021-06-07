#include<stdio.h>
#define N 100

int G[N+1][N];
int d[N+1];
int n;

void visit(int a)
{
	int i;
	
	for(i=1;i<=n;i++)
	{
		d[i]=-1;
	}
	
	re_visit(a,0);
	
	for(i=1;i<=n;i++)
	{
		printf("%d %d\n",i,d[i]);
	}
}


void re_visit(int a,int b)
{
	int i;

	if(d[a]==-1||d[a]>b)
	{
		d[a]=b;
	}
	else
	{
		return;
	}
	
	for(i=0;G[a][i]!=0;i++)
	{
		re_visit(G[a][i],b+1);
	}
}

int main(void)
{
	int u,k,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&G[u][j]);
		}
		G[u][j]=0;
	}
	
	visit(1);
	
	return 0;
}

