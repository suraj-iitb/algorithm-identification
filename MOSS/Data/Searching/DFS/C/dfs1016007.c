#include <stdio.h>
void DFS(void);
void DFS_Visit(int );
#define WHITE 0
#define BLACK 1
#define GRAY 2
#define MAX 101
int G[MAX][MAX];
int vertex[MAX],edge[MAX];
int color[MAX];
int time,n;
int d[MAX],f[MAX];  /*vの最初の時間、終了の時間*/
int main() 
{
 int i,j;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
	scanf("%d%d",&vertex[i],&edge[i]);
	for(j=1;j<=edge[i];j++)
	{
		scanf("%d",&G[vertex[i]][j]);
	}
 }

 DFS();
 for(i=1;i<=n;i++) printf("%d %d %d\n",vertex[i],d[vertex[i]],f[vertex[i]]);
 return 0;
}

void DFS()
{
 int i;
 for(i=1;i<=n;i++) color[i] = WHITE;
 time = 0;
 for(i=1;i<=n;i++)
 {
	if(color[i] == WHITE) DFS_Visit(i);
 }
}

DFS_Visit (int u)
{
 int i,v;
 color[u] = GRAY;
 d[u] = ++time;
 for(i=1;i<=edge[u];i++)
 {
 	v = G[u][i];
	if(color[v] == WHITE ) DFS_Visit(v);
 }
 color[u] = BLACK;
 f[u] = ++time;
}
