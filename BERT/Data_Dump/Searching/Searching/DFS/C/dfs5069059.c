#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n,M[N][N];
int c[N],d[N],f[N],t;
void dfs_visit(int i)
{
	int j;
	d[i]=++t;
	c[i]=G;
	for(j=0;j<n;j++)
	{
		if(M[i][j]==0)continue;
		if(c[j]==W)dfs_visit(j);
	}
	c[i]=B;
	f[i]=++t;
}//再帰を用いた深さ優先探索関数

void dfs()
{
	int i;
	t=0;
	for(i=0;i<n;i++)c[i]=W;
	for(i=0;i<n;i++)
	{
		if(c[i]==W)dfs_visit(i);
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
}//Ｃ、tの初期化を行い、未訪問のiを始点として深さ優先探索を実行、出力する
int main()
{
	int i,j,k,u,v;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)M[i][j]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&u);
		scanf("%d",&k);
		u--;
		for(j=0;j<k;j++)
		{
			scanf("%d",&v);
			v--;
			M[u][v]=1;
		}
	}
	dfs();
	return 0;
}
