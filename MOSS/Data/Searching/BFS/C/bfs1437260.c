#include<stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1

int n, G[MAX][MAX], d[MAX], color[MAX];
int Q[MAX], head=0, tail=0;

void bfs(int );
void enqueue(int );
int dequeue(void);

int main()
{
  int i, j, u, k, v;

  scanf("%d", &n);
  for(i=0; i<=n; i++)
    {
      for(j=0; j<=n; j++)
        {
          G[i][j] = 0;
        }
    }
  for(i=1; i<=n; i++)
    {
      scanf("%d %d", &u, &k);
      for(j=1; j<=k; j++)
        {
          scanf("%d", &v);
          G[u][v] = 1;
        }
      color[u] = WHITE;
      d[u] = INF;
    }

  bfs(1);

  for(i=1; i<=n; i++) printf("%d %d\n", i, d[i]);

  return 0;
}

void bfs(int s)
{
  int i, empty=0, u;

  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);
  empty++;

  while(empty != 0)
    {
      u= dequeue();
      empty--;
      for(i=1; i<=n; i++)
	{
	  if(color[i] == WHITE && G[u][i] == 1)
	    {
	      color[i] = GRAY;
	      d[i] = d[u] + 1;
	      enqueue(i);
	      empty++;
	    }
	}
      color[u] = BLACK;
    }
}

void enqueue(int s)
{
  if(tail == MAX) tail = 0;
  Q[tail] = s;
  tail++;
}

 int dequeue(void)
 {
   if(tail == MAX) tail = 0;
   return Q[head++];
 }
