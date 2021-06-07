#include <stdio.h>

#define W 0
#define G 1
#define B 2

int n, t = 0;
int color[100], d[100], f[100];
int v[100][100];
void dfs(void);
void dfsvisit(int);

main() {
  int i, j;
  
  for(i = 0; i < 100; i++) {
    color[i] = W;
    d[i] = 0;
    f[i] = 0;
  }
  scanf("%d", &n);
  
  for(i = 0; i < n; i++) {
    scanf("%d %d", &v[i][0], &v[i][1]);
    for(j = 2; j < v[i][1] + 2; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  
  dfs();

  for(i = 0; i < n; i++) {
    printf("%d %d %d\n", v[i][0], d[i], f[i]);
  }
  return 0;
}

void dfs(void) {
  int i;
  for(i = 0; i < n; i++) {
    if(color[i] == W) {
      dfsvisit(i);
    }
  }
}

void dfsvisit(int u) {
  int i;
  
  color[u] = G;
  d[u] = ++t;

  for(i = 0; i < v[u][1]; i++) {
    if(color[v[u][i + 2] - 1] == W) {
      dfsvisit(v[u][i + 2] - 1);
    }
  }
  
  color[u] = B;
  f[u] = ++t;
}
