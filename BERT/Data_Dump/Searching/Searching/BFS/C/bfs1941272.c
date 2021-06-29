#include <stdio.h>

#define N 10000
#define INFTY 1000000000
#define WHITE 0
#define GRAY 1
#define BLACK 2 

int n, Arr[N][N];
int color[N], d[N];
int Q[N], head, tail;

void BFS(int);
void enqueue(int);
int dequeue(void);

int main()
{
  int i, j;
  int u, k, v;

  scanf("%d", &n);

  head = 0;
  tail = n;
  
  for( i = 0 ; i < n ; i++ )
    for( j = 0 ; j < n ; j++ )
      Arr[i][j] = 0;

  for( i = 0 ; i < n ; i++ ){
    scanf("%d%d", &u, &k);
    u--;
    for( j = 0 ; j < k ; j++ ){
      scanf("%d", &v);
      v--;
      Arr[u][v] = 1;
    }
  }

  BFS(0);

  return 0;
}

void BFS(int s)
{
  int i, u, v;

  for( u = 0 ; u < n ; u++ ){
    color[u] = WHITE;
    d[u] = INFTY;
  }
  
  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);

  while( head != tail ){
    u = dequeue();
    for( v = 0 ; v < n ; v++ ){
      if( Arr[u][v] == GRAY && color[v] == WHITE ){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enqueue(v);
      }
    }
    color[u] = BLACK;
  }

  for( i = 0 ; i < n ; i++ ){
    printf("%d ", i+1);
    if( d[i] == INFTY ) printf("-1\n");
    else printf("%d\n", d[i]);
  }
}

void enqueue(int x)
{
  Q[tail] = x;
  tail = (tail + 1) % N;
}

int dequeue(void)
{
  int x;

  x = Q[head];
  head = (head + 1) % N;
  return x;
}
