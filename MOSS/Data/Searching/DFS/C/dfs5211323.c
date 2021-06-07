#include <stdio.h>
#define N 100

void DFS(void);
void DFS_visit(int);
int m[N][N],n;
int color[N],f[N],d[N],t;

int main()
{
  int i,j,z,v,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      m[i][j]=0;
    }
  }
  for(i=0;i<n;i++)
    {
      scanf("%d %d",&v,&z);
      v--;
      for(j=0;j<z;j++)
        {
          scanf("%d",&k);
          k--;
          m[v][k]=1;
        }
    }

  DFS();


}

void DFS()
{
  int u;
  for(u=0;u<n;u++)
    color[u]=0;
  t=0;
  for(u=0;u<n;u++)
    {
      if(color[u]==0)
        {
          DFS_visit(u);
        }
    }
  for(u=0;u<n;u++)
    {
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}

void DFS_visit(int u)
{
  int v;
  color[u]=1;
  d[u]=++t;
  for(v=0;v<n;v++)
    {
      if(m[u][v]==0)
        continue;
      if(color[v]==0)
        DFS_visit(v);
    }
  color[u]=2;
  f[u]=++t;
}

