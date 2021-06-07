#include<stdio.h>
#include<stdlib.h>

#define N 100
#define WHITE 0
#define GRAY  1
#define BLACK 2


void makenode(int,int);
void dfs(int);
void visit(int,int);

int G[N][N];

int color[N];
int d[N];
int f[N];
int times;

int main()
{
  int n,i,k,u,v,j;
  
  scanf("%d", &n);

  for(i=0;i<n;i++)
    {
      scanf("%d%d", &u, &k);
      for(j=0;j<k;j++)
	{
	  scanf("%d", &v);
	  G[u-1][v-1]=1;
	}
    }
  
  dfs(n);
  
  for(i=0;i<n;i++)
    {
      printf("%d %d %d\n", i+1, d[i], f[i]);
    }

  return 0;
}

void dfs(int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      color[i]=WHITE;
    }
  times=0;

  for(i=0;i<n;i++)
    {
      if(color[i]==WHITE)
	visit(i,n);
    }
}
void visit(int u,int n)
{
  int i;
  color[u]=GRAY;
  d[u]=++times;

  for(i=0;i<n;i++)
    {
      if(G[u][i]==1)
	{
	  if(color[i]==WHITE)
	    visit(i,n);
	}
    }
  color[u]=BLACK;
  f[u]=++times;
}
