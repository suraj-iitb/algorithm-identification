#include <stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, Arr[N][N];
int color[N], d[N], f[N], time;

void DFS(void);
void visit(int);

int main()
{
  int i, j;
  int u, v, k;

  scanf("%d", &n);

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

  DFS();

  return 0;
}

void DFS()
{
  int u;

  for( u = 0 ; u < n ; u++ ) color[u] = WHITE;
  
  time = 0;
  
  for( u = 0 ; u < n ; u++ ) 
    if( color[u] == WHITE ) visit(u);

  for( u = 0 ; u < n ; u++ ) printf("%d %d %d\n", u+1, d[u], f[u]);
}

void visit(int r)
{
  int v;

  color[r] = GRAY;
  d[r] = ++time;

  for( v = 0 ; v < n ; v++ ){
    if( Arr[r][v] == 0 ) continue;
    if( color[v] == WHITE ) visit(v);
  }
  color[r] = BLACK;
  f[r] = ++time;
}
