#include<stdio.h>
#define N 100

int n, G[N][N];
int d[N];
void wfs(int a, int len)
{
  int i;
  len++;
    d[a] = len;
  for(i = 0; i < n; i ++)
    {
      if(G[a][i] == 1)
	{
	  if(d[i] <= len && d[i] >= 0)
	    {
	      continue;
	    }
	  wfs(i, len);
	}
    }
}

int main()
{
  int i, j, k, u, v;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  G[i][j] = 0;
	}
    }

  for(i = 0; i < n; i++)
    {
      scanf("%d %d", &u, &k);
      u--;
      for(j = 0; j < k; j++)
	{
	  scanf("%d", &v);
	  v--;
	  G[u][v] = 1;
	}
    }
  for(i = 0; i < n; i++)
    {
      d[i] = -1;
    }
  wfs(0, -1);
  for(i = 0; i < n; i++)
    {
      printf("%d %d\n", i+1, d[i]);
    }
  return 0;
} 

