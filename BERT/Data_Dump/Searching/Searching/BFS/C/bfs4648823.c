#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define N 110
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define inf 99999999
int n,GMatrices[N][N]={0};
int color[N],d[N];
struct queue
{
	int q[N];
	int head;
	int tail;
};
struct queue Q;
void bfs()
{
	Q.head=1;
	Q.tail=1;
	for(int i=1;i<=n;i++)
		color[i]=WHITE;
	for(int i=1;i<=n;i++)
		d[i]=inf;
	color[1]=GRAY;
	d[1]=0;
	Q.q[Q.tail]=1;
	Q.tail++;
	while(Q.head!=Q.tail)
	{
		for(int v=1;v<=n;v++)
			if(GMatrices[Q.q[Q.head]][v] && color[v]==WHITE)
			{
				color[v]=GRAY;
				d[v]=d[Q.q[Q.head]]+1;
				Q.q[Q.tail]=v;
				Q.tail++;
			}
		color[Q.q[Q.head]]=BLACK;
		Q.head++;
	}
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
	bfs();
	for(int i=1;i<=n;i++)
		if(d[i]!=inf)
			printf("%d %d\n",i,d[i]);
		else
			printf("%d %d\n",i,-1);
	return 0;
}
