#include <stdio.h>
#include <stdlib.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, A[N][N], d[N], color[N];
int Q[N+1];
int head = 0, tail = 0;

void BFS(int);
void enqueue(int);
int dequeue(void);

int main()
{
  int i, j, u, k, v;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  A[i][j] = 0;
	}
    }

  for(i = 0; i < n; i++)
    {
      scanf("%d %d",&u,&k);
      u--;
      for(j = 0; j < k; j++)
	{
	  scanf("%d",&v);
	  v--;
	  A[u][v] = 1;
	}
    }

  BFS(0);
  
  return 0;
}

void BFS(int x)
{
  int u, v;
  for(u = 0; u < n; u++)
    {
      color[u] = WHITE;
      d[u] = -1;
    }

  color[x] = GRAY;
  d[x] = 0;
  enqueue(x);

  while(head != tail)
    {
      u = dequeue();
      for(v = 0; v < n; v++)
	{
	  if(A[u][v] == 1 && color[v] == WHITE)
	    {
	      color[v] = GRAY;
	      d[v] = d[u]+1;
	      enqueue(v);
	    }
	}
       color[u] = BLACK;
    }

  for(u = 0; u < n; u++)
    {
      printf("%d %d\n",u+1,d[u]);
    }
}

void enqueue(int x)
{
  Q[tail] = x;
  if(tail+1 == N)tail = 0;
  else tail++;
}

int dequeue(void)
{
  int x;
  x = Q[head];
   if(head+1 == N)head = 0;
   else head++;
   return x;
}

