#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfsvisit(int);

int color[101];
int d[101];
int f[101];
int ti=0;
int adj[101][101];
int k[100];

int main()
{
  int n,i=0,j=0;
  int tmp;


  for(i=0;i<101;i++)
    {
      color[i] = WHITE;
    }

  scanf("%d",&n);

  for(i=1;i<=n;i++)
    {
      scanf("%d",&tmp);
      scanf("%d",&k[i]);
      for(j=0;j<k[i];j++)
	{
	  scanf("%d",&adj[i][j]);
	}
    }
 
  for(i=1;i<=n;i++)
    {
      if(color[i] == WHITE)
	{
	  dfsvisit(i);
	}
    }
  for(i=1;i<=n;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }

  return 0;
  }

void dfsvisit(int u)
{
  int i;
  color[u] = GRAY;
  d[u] = ++ti;
  for(i=0;i<k[u];i++)
    {
      if(color[adj[u][i]] == WHITE)
	{
	  dfsvisit(adj[u][i]);
	}
    }
  color[u] = BLACK;
  f[u] = ++ti;
}
