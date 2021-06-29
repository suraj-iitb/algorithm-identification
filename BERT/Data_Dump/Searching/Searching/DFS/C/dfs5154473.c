#include<stdio.h>

#define N 101
#define BLACK 2
#define WHITE 0
#define GRAY 1

int n;/*頂点*/
int M[N][N],color[N];
int d[N];/*発見時刻*/
int f[N];/*完了時刻*/
int time;

void visit(int u)
{
  int i;

  color[u] = GRAY;
  d[u] = ++time;

  for(i = 1;i <= n; i++)
    {
      if(M[u][i] == 1)
        {
          if(color[i] == WHITE)
            {
              visit(i);
            }
        }
    }
  color[u] = BLACK;

  f[u] = ++time;
}

void dfs(void)
{
  int i;

  for(i = 1;i <= n; i++)
    {
      color[i] = WHITE;
    }
  for(i = 1;i <= n; i++)
    {
      if(color[i] == WHITE)visit(i);
    }
}

int main()
{
  int i,j,y,num,v;

  scanf("%d",&n);

  for(i = 1;i <= n; i++)
    {
      scanf("%d%d",&y,&num);

      for(j = 0;j < num; j++)
        {
          scanf("%d",&v);

          M[i][v] = 1;
        }
    }

  dfs();

  for(i = 1;i <= n; i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }

  return 0;

}
