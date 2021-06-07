#include <stdio.h>

int n;
int A[101][101];

int d[101], f[101];
int cnt;

void dfs(int u) {
  int i;
  if(d[u]) return;
  d[u] = ++cnt;
  for(i = 0; i < n; i++) if(A[u][i] == 1) dfs(i);
  f[u] = ++cnt;
}

int main() {
  int i, j;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    int u, k;
    scanf("%d %d", &u, &k);
    --u;
    for(j = 0; j < k; j++) {
      int v;
      scanf("%d", &v);
      --v;
      A[u][v] = 1;
    }
  }

  for(i = 0; i < n; i++) dfs(i);

  for(i = 0; i < n; i++) printf("%d %d %d\n", i+1, d[i], f[i]);

  return 0;
}
