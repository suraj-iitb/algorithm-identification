#include<stdio.h>
#define N 100

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, A[N][N];
int color[N], depth[N], first[N], c;

void dfs_visit(int u){
  int i;
  color[u] = GRAY;
  c++;
  depth[u] = c;
  for ( i = 0; i < n; i++ ){
    if ( A[u][i] == 0 ) 
        continue;
    if ( color[i] == WHITE ){
      dfs_visit(i);
    }
  }
  color[u] = BLACK;
  first[u] = ++c;
}

void DFS(){
  int i, u;
  for ( i = 0; i < n; i++ ) 
    color[i] = WHITE;

  c = 0;
  for ( u = 0; u < n; u++ ){
    if ( color[u] == WHITE )
         dfs_visit(u);
  }
  for ( i = 0; i < n; i++ ){
    printf("%d %d %d\n", i+1, depth[i], first[i]);
  }
}


main(){
  int u, k, v;
  int i, j;

  scanf("%d", &n);

  for ( i = 0; i <n; i++ ){
    for ( j = 0; j <n; j++ )
         A[i][j] = 0;
  }
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &u, &k);
    u--;

    for ( j = 0; j < k; j++ ){
        scanf("%d", &v);
        v--;
        A[u][v] = 1;
    }
  }

  DFS();

  return 0;
}
