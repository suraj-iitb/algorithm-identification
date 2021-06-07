#include<stdio.h>
#include<limits.h>
#define WHITE 0
#define GRAY -1
#define BLACK 1

void enqueue(int);
int dequeue();
void BFS(int);
int Q[101], G[101][101], d[101], color[101], head, tail ,n;

main()
{
  int i, j, k, u, value;

  for(i=1 ; i<=101 ; i++)
    {
      for(j=1 ; j<=101 ; j++)
        {
          G[i][j] = 0;
        }
    }

  scanf("%d",&n);
  for(i=1 ; i<=n ; i++)
    {
      scanf("%d%d",&u ,&k);
      for(j=1 ; j<=k ; j++)
        {
          scanf("%d",&value);
          G[u][value] = 1;
        }
    }
  
  for(i=1 ; i<101 ; i++)
    {
    d[i] = -1;
    }
  
  BFS(1);

  for(i=1 ; i<=n ; i++)
    {
      if(d[i] == INT_MAX) d[i] = -1;
      printf("%d %d\n",i ,d[i]);
    }
   
  return 0;
}

void enqueue(int x)
{
  Q[tail] = x;
  if(tail == 101) tail = 1;
  else tail++;
}


int dequeue()
{
  int data;
  data = Q[head];

  if(head == 101) head = 1;
  else head++;

  return data;
}

void BFS(int s)
{
  int i, u, v;

  for(u=1 ; u<=n-1 ; u++)
    {
      color[u] = WHITE;
      d[u] = INT_MAX;
    }

  color[s] = GRAY;
  d[s] = 0;
  head = tail = 0;
  enqueue(s);

  while(head != tail)
    {
      u = dequeue();
      for(v=1 ; v<=n ; v++)
        {
          if(G[u][v] == 1 && color[v] == WHITE)
            {
              color[v] = GRAY;
              d[v] = d[u] + 1;
              enqueue(v);
            }
        }
      color[u] = BLACK;
    }
}
