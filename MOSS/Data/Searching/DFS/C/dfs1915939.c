#include <stdio.h>
#define MAX 101

void dfs();
void reVisit(int);

int Adj[MAX][MAX];
int D[MAX];
int F[MAX];
int n, time;

int main()
{
  int i, j;
  int u, v, k;

  scanf("%d", &n);
  for(i = 1; i <= n; i++)
    {
      for(j = 1; j <= n; j++)
	{
	  Adj[i][j] = 0;
	}
    }
  for(i = 1; i <= n; i++)
    {
      scanf("%d %d", &u, &k);
      for(j = 1; j <= k; j++)
	{
	  scanf("%d", &v);
	  Adj[u][v] = 1;
	}
    }

  dfs();

  for(i = 1; i <= n; i++)
    {
      printf("%d %d %d\n", i, D[i], F[i]);
    }

 return 0;
}

void dfs()
{
  int i;

  time = 0;

  for(i = 0; i < n; i++)
    {
      D[i] = 0;
      F[i] = 0;
    }

  for(i = 1; i <= n; i++)
    {
      if(D[i] == 0)
	reVisit(i);
    }
}

void reVisit(int u)
{
  int i, j;

  D[u] = ++time;


  for(i = 1; i <= n; i++)
    {
      if(Adj[u][i] == 1 && D[i] == 0)
	{
	  reVisit(i);
	}
    }

  F[u] = ++time;
}
