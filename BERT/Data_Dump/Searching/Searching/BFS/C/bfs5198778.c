#include <stdio.h>

#define N 105

int n, array[N][N], cost[N],queue[10000];
int head = 0, tail = 0;

void enqueue( int x )
{
  queue[tail] = x;
  tail++;
}

int dequeue()
{
  if( head == tail )
    return -1;
  return queue[head++];
}

void BFS()
{
  int id,i;

  enqueue( 1 );
  cost[1] = 0;

  while( (id = dequeue()) != -1 )
    {
      for( i = 1; array[id][i] != -1; i++ )
	{
	  if( cost[array[id][i]] == -1 )
	    {
	      cost[array[id][i]] = cost[id]+1;
	      enqueue( array[id][i] );
	    }
	}
    }

  for( i = 1; i <= n; i++ )
    printf("%d %d\n",i,cost[i]);
}

int main()
{
  int i,j;
  int u,k,v;
  
  scanf("%d",&n);

  for( i = 1; i <= n; i++ )
    {
      cost[i] = -1;
      scanf("%d %d",&u, &k);
      for( j = 1; j <= k; j++ )
	{
	  scanf("%d",&v);
	  array[u][j] = v;
	}
      array[u][j] = -1;
    }

  BFS();

  return 0;
}

