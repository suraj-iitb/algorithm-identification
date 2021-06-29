#include <stdio.h>

#define N 101
 
int A[N][N],color[N],f[N],d[N];
int n,time,k,a;
 
void visit(int );
void dSearch(void);
 
 
int main()
{
  int i, j, u, k;

  scanf("%d",&n);

  for(i = 0;i <= n;i ++ )
    {
    for(j = 0 ;j <= n;j ++ )
      {
      A[i][j] = 0;
      }
    }
  
  for(i = 1 ;i <= n;i ++ )
    {
    scanf("%d",&u);
    scanf("%d",&k);
    for(j = 1;j <= k;j ++ )
      {
      scanf("%d",&a);
      A[u][a] = 1;
    }
  }
  dSearch();
 
  for(i = 1;i <= n;i ++)
    {
    printf("%d %d %d\n",i,d[i],f[i]);
    }
  
  return 0;
}

void visit(int u)
{
  int i;

  color[u] = 2;

  d[u] = ++time;

  for(i = 1;i <= n; i ++)
    {
    if(A[u][i] != 0)
      {
      if(color[i] == 0) visit(i);
    }
  }
  color[u] = 3;
  f[u] = ++time;
}
 
void dSearch(void)
{
  int i;
  for(i = 1;i <= n ; i++)
    {
    color[i] = 0;
    }
  
  time = 0;
  
  for(i = 1;i <= n ;i ++ )
    {
    if(color[i] == 0)visit(i);
    }
}
