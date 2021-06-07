#include <stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK -1

int adj[MAX][MAX];
int d[MAX], f[MAX], color[MAX];

void visit(int u, int n){
  int i, j;
  static int time = 0;

  color[u] = GRAY;
  d[u] = ++time;

  for( j = 1; j <= n; j++){
    if( adj[u][j] == 1 ){
      if( color[j] == WHITE ) visit(j, n);
    }
  }

  color[u] = BLACK;
  f[u] = ++time;

}


void depthFirstSearch(int n){
  int i;

  for( i = 0; i < n; i++){
    color[i] = WHITE;
  }

  for( i = 1; i <= n; i++){
    if( color[i] == WHITE ) visit(i, n);
  }

}


main(){
  int i, j, n, k, u, v;

  scanf("%d", &n);

  for( i = 1; i <= n; i++){
    scanf("%d%d", &u, &k);
    for( j = 1; j <= k; j++){
      scanf("%d", &v);
      adj[i][v] = 1;
    }
  }

  depthFirstSearch(n);

  for( i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;

}
