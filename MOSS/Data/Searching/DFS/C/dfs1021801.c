#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int d[101],f[101],Adj[101][101],color[101];
int time;
int n;

void DFS_Visit(int u)
{
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=1;i<=n;i++)
    {
      if(Adj[u][i]==1&&color[i]==WHITE)
	{
	  DFS_Visit(i);
	}
    }
  color[u]=BLACK;
  f[u]=++time;
}

void DFS(void)
{
  int i;
  for(i=1;i<=n;i++)
    {
      color[i]=WHITE;
      time=0;
    }
  for(i=1;i<=n;i++)
    {
      if(color[i]==WHITE)
	{
	  DFS_Visit(i);
	}
    }
}



main()
{
  int i,j;
  int u,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      for(i=1;i<=n;i++)
	{
	  Adj[i][j]=0;
	}
    }

  for(i=1;i<=n;i++)
    {
      scanf("%d%d",&u,&k);
      for(j=1;j<=k;j++)
	{
	  scanf("%d",&v);
	  Adj[u][v]=1;
	}
    }
  DFS();
  for(i=1;i<=n;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }
  return 0;
}
