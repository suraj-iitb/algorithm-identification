#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int p, n, Z[N][N], id[N], d[N], f[N];

void dfs_visit(int i){
  int j;

  id[i] = GRAY;
  d[i] = ++p;

  for(j = 0; j < n; j++){
    if(Z[i][j] == 0) continue;
    if(id[j] == WHITE) dfs_visit(j);
  }

  id[i] = BLACK;
  f[i] = ++p;
}

void dfs(){
  int i;

  for(i = 0; i < n; i++) id[i] = WHITE;
  
  p = 0;

  for(i = 0; i < n; i++){
    if(id[i] == WHITE) dfs_visit(i);
  }

  for(i = 0; i < n; i++){
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }
}

int main(){
  int i, j, u, v, k;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      Z[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d %d", &u, &k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      v--;
      Z[u][v] = 1;
    }
  }

  dfs();

  return 0;
}

