#include<stdio.h>

#define MAX 101
#define WHITE -3
#define GRAY -2
#define BLACK -1

void dfs(void);
void visit(int);

int n;/*頂点数*/
int M[MAX][MAX];/*行＝要素、列＝繋がっている要素*/
int color[MAX];/*色分け用の配列*/
int d[MAX];/*要素を最初に発見した発見時刻を記録する用配列*/
int f[MAX];/*要素の隣接リストを調べ終えた完了時刻を記録する用配列*/
int time;

int main()
{
	int i, j, element, number, v;

	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&element,&number);

		for(j=0;j<number;j++)
		{
			scanf("%d",&v);
			M[i][v]=1;
		}
	}

	dfs();

	for(i=1;i<=n;i++)
	{
		printf("%d %d %d\n",i,d[i],f[i]);
	}
	return 0;
}

void dfs(void)
{
	int i;
	for(i=1;i<=n;i++)
	{
		color[i] = WHITE;
	}
	for(i=1;i<=n;i++)
	{
		if(color[i] == WHITE) visit(i);
	}
}

void visit(int u)
{
	int i;
	color[u] = GRAY;
	d[u] = ++time;

	for(i=1;i<=n;i++)
	{
		if(M[u][i] == 1)
		{
			if(color[i] == WHITE)
			{
				visit(i);
			}
		}
	}
	color[u] = BLACK;
	f[u] = ++time;
}
