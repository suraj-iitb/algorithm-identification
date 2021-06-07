#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int d[101], f[101], color[101];
int A[101][101];
int n, t;

void visit(int u) {
  int v;
  color[u] = GRAY;
  d[u] = ++t;

  for (v = 1; v <= n; v++) {
    if (color[v] == WHITE && A[u][v] == 1) visit(v);
  }
  color[u] = BLACK;
  f[u] = ++t;
}

void dfs() {
  int u;
  for (u = 1; u <= n; u++) {
    color[u] = WHITE;
  }
  t = 0;
  for (u = 1; u <= n; u++) {
    if (color[u] == WHITE) {
      visit(u);
    }
  }
}

int main() {
  int i, j, u, k, v;

  scanf("%d\n", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &u, &k);
    for (j = 1; j <= k; j++) {
      scanf("%d ", &v);
      A[u][v] = 1;
    }
  }

  dfs();
  for (i = 1; i <= n; i++) {
    printf("%d %d %d\n", i, d[i], f[i]);
  }


  return 0;
}
