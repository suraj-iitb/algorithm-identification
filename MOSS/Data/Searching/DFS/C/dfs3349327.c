#include<stdio.h>
#define N 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,A[N][N],color[N],d[N],f[N],time;
void visit(int r)
{
  int v;
  color[r]=GRAY;
  d[r]=++time;
  for(v=0;v<n;v++)
    {
      if(A[r][v]==0)
	{
	  continue;
	}
      if(color[v]==WHITE)
	{
	  visit(v);
	}
    }
  color[r]=BLACK;
  f[r]=++time;
}
  
void dfs()
{
  int u;
  for(u=0;u<n;u++)
    {
      color[u]=WHITE;
      time=0;
    }
      for(u=0;u<n;u++)
	{
	  if(color[u]==WHITE)
	    {
	      visit(u);
	    }
	}
      for(u=0;u<n;u++)
	{
	  printf("%d %d %d\n",u+1,d[u],f[u]);
	}
}


int main()
{
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	{
	  A[i][j]=0;
	}
    }
  for(i=1;i<=n;i++)
    {
      scanf("%d%d",&u,&k);
      u--;
      for(j=1;j<=k;j++)
      {
	scanf("%d",&v);
	v--;
	A[u][v]=1;
      }
    }
  dfs();
	    

  return 0;
}

