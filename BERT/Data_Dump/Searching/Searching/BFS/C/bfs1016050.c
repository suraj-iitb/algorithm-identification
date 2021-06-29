#include <stdio.h>
#define INF -1
#define WHITE 0
#define BLACK 1
#define GRAY 2
#define MAX 101
void BFS();
int Dequeue();
void Enqueue(int );
int G[MAX][MAX];
int Q[MAX],head=0,tail=0;
int vertex[MAX],edge[MAX];
int color[MAX];
int time,n;
int d[MAX];  /*頂点からの距離*/
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
 BFS(vertex[1]);
 for(i=1;i<=n;i++) printf("%d %d\n",vertex[i],d[vertex[i]]);
 return 0;
}

void BFS(int s)
{
 int i,empty,u,v;
 for(i=1;i<=n;i++)
 {
 	color[i] = WHITE;
 	d[i] = INF;
 }
 color[s] = GRAY;
 d[s] = 0;
 empty = 0;
 Enqueue(s);
 empty++;
 while( empty != 0)
 {
	u = Dequeue();
	empty--;
	for(i=1;i<=edge[u];i++)
	{
		v = G[u][i];
		if(color[v] == WHITE)
		{
			color[v] = GRAY;
			d[v] = d[u]+1;
			Enqueue(v);
			empty++;
		}
	}
 }
 color[u] = BLACK;
}

int Dequeue()
{
 if(head == MAX) head = 0;
 return Q[head++];
}

void Enqueue(int value)
{
 if(tail == MAX) tail =0;
 Q[tail++] = value;
}
