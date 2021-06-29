#include <stdio.h>

#define N 100
#define B 2
#define G 1
#define W 0

int n,M[N][N];
int co[N],d[N],f[N],t;

void search(int x)
{
  int y;
  co[x]=G;
  d[x]=++t;

  for(y=0; y<n; y++)
  {
    if(M[x][y]==0) continue;
    if(co[y]==W) search(y);
  }

  co[x]=B;
  f[x]=++t;
}

void dfs()
{
  int x;

  for(x=0; x<n; x++) co[x]=W;
  t=0;

  for(x=0; x<n; x++) if(co[x]==W) search(x);

  for(x=0; x<n; x++) printf("%d %d %d\n",x+1,d[x],f[x]);
}

int main()
{
  int u,v,i,j,k;

  scanf("%d",&n);
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++) M[i][j]=0;
  }

  for(i=0; i<n; i++)
  {
    scanf("%d %d",&u,&k);
    u--;

    for(j=0; j<k; j++)
    {
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  dfs();

  return 0;
}
