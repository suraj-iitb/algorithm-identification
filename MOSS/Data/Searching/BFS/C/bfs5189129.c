#include <stdio.h>

#define WHITE -3
#define GLAY -2
#define BLACK -1
#define MAX 101

void bfs(int);
void enqueue(int);
int dequeue(void);

int T[MAX][MAX];
int color[MAX];
int d[MAX];
int n;
int head,tail;
int Q[MAX];

int main()
{
  int i,j,array,num,v;

  scanf("%d",&n);

  for(i = 1;i <= n; i++)
    {
      scanf("%d%d",&array,&num);

      for(j = 0;j < num; j++)
        {
          scanf("%d",&v);

          T[i][v] = 1;
        }
    }

  bfs(1);

  for(i = 1;i <= n; i++)
      {
      printf("%d %d\n", i, d[i]);
    }

  return 0;
}

void bfs(int s)
{
  int i,u,v;

  for(i = 1;i <= n; i++)
    {
      color[i] = WHITE;
      d[i] = -1;
    }
  color[s] = GLAY;
  d[s] = 0;
  enqueue(s);

  while(head != tail)
    {
      u = dequeue();

      for(v = 1;v <= n; v++)
        {
          if(T[u][v] == 1)
            {
              if(color[v] == WHITE)
                {
                  color[v] = GLAY;
                  d[v] = d[u] + 1;
                  enqueue(v);
                }
            }
        }
      color[u] = BLACK;
    }
}

void enqueue(int u)
{
  Q[tail] = u;
  tail++;
  if(tail == MAX)
    {
      tail = 0;
    }
}

int dequeue(void)
{
  int u;

  u = Q[head];
  head++;

  if(head == MAX)
    {
      head = 0;
    }
  return u;
}

