#include <stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[N][N];
int color[N],d[N],f[N],tt;

void dfs_visit(int i)
{
  int j;
  color[i]=GRAY;
  d[i]=++tt;
  for(j=0;j<n;j++)
  {
    if(M[i][j]==0)continue;
    if(color[j]==WHITE)
    {
      dfs_visit(j);
    }
  }
  color[i]=BLACK;
  f[i]=++tt;
}

void dfs()
{
  int i;
  for(i=0;i<n;i++)
  {
    color[i]=WHITE;
  }
  tt=0;
  for(i=0;i<n;i++)
  {
    if(color[i]==WHITE)dfs_visit(i);
  }
  for(i=0;i<n;i++)
  {
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

int main()
{
  int i,j,id,n2,v;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++)
  {
    scanf("%d %d",&id,&n2);
    {
      id=id-1;
      for(j=0;j<n2;j++)
      {
        scanf("%d",&v);
        v=v-1;
        M[id][v]=1;
      }
    }
  }
  dfs();
  return 0;
}

