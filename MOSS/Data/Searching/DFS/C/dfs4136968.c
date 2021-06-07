#include <stdio.h>
#define W 0
#define G 1
#define B 2

int M[100][100],n,d[100],f[100],c[100],tt;

void dfs_visit(int u)
{
  int i;
  c[u]=G;
  d[u]= ++tt;
  for(i=0;i<n;i++)
    {
      if(c[i]==W&&M[u][i]==1)
	dfs_visit(i);
    }
  f[u]=++tt;
  c[u]=B;
}

void dfs(void)
{
  int u;

  for(u=0;u<n;u++)
    {
      c[u]=W;
    }

  tt=0;
  for(u=0;u<n;u++)
    {
      if(c[u]==W)
	dfs_visit(u);
    }

  for(u=0;u<n;u++)
    {
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}

int main()
{
  int i,j;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  M[i][j]=0;
	}
    }

  int k,u,v;
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&u);
      scanf("%d",&k);
      for(j=0;j<k;j++)
	{
	  scanf("%d",&v);
	  M[u-1][v-1]=1;
	}
    }

  dfs();

  return 0;
}

  

  

  

