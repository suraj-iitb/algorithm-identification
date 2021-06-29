#include<stdio.h>

#define MAX 100
#define INFTY 1000000000

int n, d[MAX], M[MAX+1][MAX+1], queue[MAX], head=0, tail=0;

int dequeue()
{
  int x;
  x = queue[head];
  if( head + 1 == MAX + 1 ) head = 0;
  else head++;

  return x;
}

void enqueue( int x )
{
  queue[tail] = x;
  if( tail + 1 == MAX + 1) tail = 0;
  else tail++;
}

int empty()
{
  if( head == tail ) return 1;
  else return 0;
}

void dfs( int s )
{
  int i, u, v;

  enqueue(s);

  for( i=0; i<n; i++ )
    {
      d[i] = INFTY;
    }

  d[s] = 0;

  while( empty() != 1 )
    {
      u = dequeue();

      for( v=0; v<n; v++ )
	{
	  if( M[u][v] == 0 ) continue;
	  if( d[v] != INFTY ) continue;
	  d[v] = d[u] + 1;
	  enqueue(v);
	}
    }

  for( i=0; i<n; i++ )
    {
      printf("%d ", i+1);
      if( d[i] == INFTY )
	{
	printf("-1\n");
	continue;
      }
      printf("%d\n", d[i]);
    }

}

int main()
{
  int i, j, u, k, v;

  scanf("%d", &n);

  for( i=0; i<n; i++ )
    {
      for( j=0; j<n; j++ )
	{
	  M[i][j] = 0;
	}
    }

  for( i=0; i<n; i++ )
    {
      scanf("%d%d", &u, &k);
      u--;

      for( j=0; j<k; j++ )
	{
	  scanf("%d", &v);
	  v--;
	  M[u][v] = 1;
	}
    }

  dfs(0);

  return 0;

}

