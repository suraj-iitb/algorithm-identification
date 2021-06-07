#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int A[N][N], color[N];
int d[N], f[N];
int time, n;

void dfs(void);
void visit(int);

int main() {
  int u, v, k, i, j;

  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      A[i][j] = 0;
    }
  }

  for(i = 1; i <= n; i++) {
    scanf("%d", &u);
    scanf("%d", &k);
    for(j = 1; j <= k; j++) {
      scanf("%d", &v);
      A[u][v] = 1;
    }
  }

  dfs();

  for(i = 1; i <= n; i++) {
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;
}


void dfs() {
  int i;
  for(i = 1; i <= n; i++) {
    color[i] = WHITE;
  }
  time = 0;
  for(i = 1; i<= n; i++) {
    if(color[i] == WHITE) visit(i);
  }
}


void visit(u) {
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i = 1; i<= n; i++) {
    if(A[u][i] == 1) {
      if(color[i] == WHITE) visit(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}
