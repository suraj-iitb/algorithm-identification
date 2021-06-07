#include <stdio.h>
#include <string.h>
#define p1 0
#define p2 1
#define p3 2

void visit(int );
void dfs();

int n,A[100][100],c[100],d[100],f[100],t;

int main()
{
  int i,j,u,v,k;

  for(i = 0;i < n;i++)
    {
      for(j = 0;j < n;j++)
	{
	  A[i][j] = 0;
	}
    }
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      scanf("%d",&u);
      scanf("%d",&k);
      if(k == 0) continue;
	/*{
	  for(l = 0;l < n;l++)
	    {
	      A[u-1][l] = 0;
	      }*/
      for(j = 0;j < k;j++)
	{
	  scanf("%d",&v);
	  A[u-1][v-1] = 1;
	}
    }
  dfs();
    
  return 0;
}
void dfs()
{
  int i;
  for(i = 0;i < n;i++)
  {
    c[i] = p1;
  }
  t = 0;
  for(i = 0;i < n;i++)
    {
      if(c[i] == p1) visit(i);
    }
  for(i = 0;i < n;i++)
    {
      printf("%d ",i + 1);
      printf("%d ",d[i]);
      printf("%d\n",f[i]);
    }
}
void visit(int r)
{
  int x;
  c[r] = p2;
  d[r] = ++t;
  for(x = 0;x < n;x++)
    {
      if(A[r][x] == 0) continue;
      if(c[x] == p1)
	{
	  visit(x);
	}
    }
  c[r] = p3;
  f[r] = ++t;
}
  
  
    
  
  

