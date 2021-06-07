#include <stdio.h>

void bfs(void);
void visit(int);

int n, G[101][101] ={0}, color[101], d[101], Q[101] ={0};

int main()
{
  int i, j, u, k, a;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d",&u);
      scanf("%d",&k);
      for(j = 0; j < k; j++)
	{
	  scanf("%d",&a);
	  G[u][a] = 1;
	}
    }
  bfs();
  return 0;
}

void bfs(void)
{
  int i, u, q_start=1, q_end=1;

  for(i = 1; i <= n; i++)
    {
      color[i] = 0;
      d[i] = -1;
    }
  color[1] = 0;
  d[1] = 0;
  Q[1]=1;
  q_end++;
  while(q_start != q_end)
    {
      u = Q[q_start];
      q_start++;
      for(i = 1; i <= n; i++)
	{
	  if(G[u][i] == 1 && color[i] == 0)
	    {
	      color[i] = 1;
	      d[i] = d[u] + 1;
	      Q[q_end] = i;
	      q_end++;
	    }
	  color[u] = 2;
	}
    }
  for(i = 1; i <= n; i++)
    {
      printf("%d %d\n",i, d[i]);
    }
}


