#include<stdio.h>

int root[101][101];
int T[101];
int n;

void bfs(int  s,int c)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(root[s][i+1]==1 && c < T[i+1])
		{
			T[i+1]=c;
			bfs(i+1,c+1);
		}
	}
}

int main(void)
{
	int i,j,u,k,v,s,m,l;
	scanf("%d",&n);
	
	for(s=0;s<n;s++)
	{
		T[s+1]=9999999;
	}
	
	T[1]=0;
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&v);
			root[u][v]=1;
		}
	}
	
	bfs(1,1);
	
	for(m=0;m<n;m++)
	{
		printf("%d ",m+1);
		if(T[m+1]==9999999)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",T[m+1]);
		}
	}
	
	return 0;
}
