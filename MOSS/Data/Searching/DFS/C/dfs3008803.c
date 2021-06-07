#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define N 100

int G[N + 1][N + 1];
int d[N + 1], f[N + 1];
int t = 0;

void dfs(int u) {
  int i;

  if(d[u])
    return;

  d[u] = ++t;

  for(i = 0;i < N + 1;i++)
    if(G[u][i] == 1)
      dfs(i);

  f[u] = ++t;
  return;
}

int main() {
  int i, j, k;
  int u, v, w;
  int n;

  for(i = 0;i < N + 1;i++) {
    d[i] = 0;
    f[i] = 0;
    for(j = 0;j < N + 1;j++)
      G[i][j] = 0;
  }

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    scanf("%d %d", &u, &k);
    for(j = 0;j < k;j++) {
      scanf("%d", &w);
      G[u][w] = 1;
    }
  }

  for(i = 1;i < n + 1;i++)
    dfs(i);

  for(i = 1;i < n + 1;i++)
    printf("%d %d %d\n", i, d[i], f[i]);
}

