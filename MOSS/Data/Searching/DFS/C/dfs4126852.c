#include<stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS();
void tourist(int );

int k, G[MAX][MAX], d[MAX], clr[MAX], f[MAX], num=0;

int main()
{
  int i, j, u, r, n;

  scanf("%d", &k);
  for(i=0; i<=k; i++)
    {
      for(j=0; j<=k; j++)
	{
	  G[i][j] = 0;
	}
    }
  for(i=1; i<=k; i++)
    {
      scanf("%d %d", &u, &n);
      for(j=1; j<=n; j++)
	{
	  scanf("%d", &r);
	  G[u][r] = 1;
	}
      clr[u] = WHITE;
    }

  DFS();

  for(i=1; i<=k; i++) printf("%d %d %d\n", i, d[i], f[i]);

  return 0;
}

void DFS()
{
  int i; 

  for(i=1; i<=k; i++)
    {
      if(clr[i] == WHITE) tourist(i);
    }
}

void tourist(int u)
{
  int i;

  clr[u] = GRAY;
  d[u] = ++num;

  for(i=1; i<=k; i++)
    {
      if(G[u][i] == 1 && clr[i] == WHITE) 
	{
	  tourist(i);
	}
    }
  clr[u] = BLACK;
  f[u] = ++num;
}

