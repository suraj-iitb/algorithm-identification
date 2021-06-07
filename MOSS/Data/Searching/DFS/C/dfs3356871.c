#include <stdio.h>

#define WHITE 1
#define GRAY 2
#define BRACK 3

int n,color[101],time,d[101],f[101],G[101][101];

void visit(int u)
{
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for(v = 1;v <= n;v++)
    {
      if(G[u][v] == 1 && color[v] == WHITE)
	{
	  visit(v);
	}
    }
  color[u] = BRACK;
  f[u] = ++time;
  
}

void dfs()
{
  int u;
  for(u = 1;u <= n;u++)
    {
      color[u] = WHITE;
    }
  time = 0;
  for(u = 1;u <= n;u++)
    {
      if(color[u] == WHITE)
	{
	  visit(u);
	}
    }
}



int main()
{
  int i,u,k,j,v;
  
  scanf("%d",&n);

  for(i = 1;i <= n;i++)
    {
      scanf("%d %d",&u,&k);
      for(j = 1;j <= k;j++)
	{
	  scanf("%d",&v);
	  G[u][v] = 1;
	}     
    }
  dfs();

  for(i = 1;i <= n;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }

  return 0;  
  
}
