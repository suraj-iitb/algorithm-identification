#include <stdio.h>

#define N 100
#define white 0 //未訪問の頂点
#define gray 1 //訪問した頂点
#define black 2 //訪問が完了した頂点

int n,G[N][N];
int color[N],d[N],f[N],TIME=0;
//color[i]はその頂点iの訪問状況を表す。d[i]はiを最初に発見した時刻を記録。f[i]はiの隣接リストを調べ終えた完了時刻を記録。

void visit(int );
void dfs(void);

int main()
{
  int u,v,k;
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          G[i][j]=0;
        }
    }

  for(i=0;i<n;i++)
    {
      scanf("%d%d",&u,&k);
      u--;
      for(j=0;j<k;j++)
        {
          scanf("%d",&v);
          v--;
          G[u][v] = 1;
        }
    }
     dfs();

  return 0;
}

void visit(int u)
{
  int v;
  color[u] = gray;
  d[u] = ++TIME;
  for(v=0;v<n;v++)
    {
      if(G[u][v] == 0) continue;
      if(color[v] == white)
        {
          visit(v);
        }
    }
  color[u] = black;
  f[u] = ++TIME;
}

void dfs(void)
{
  int u;

  for(u=0;u<n;u++) color[u] = white;

  for(u=0;u<n;u++)
    {
      if(color[u] == white) visit(u);
    }
  for(u=0;u<n;u++)
    {
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}
