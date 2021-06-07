#include <stdio.h>
#define N 100

int n, M[N][N];
int d[N], q[N];

void bfs(int s) {
  int u, v, i, x = 0, m = 0;
  
  for (i = 0; i < n; i++) {
    d[i] = 101;
  }
  
  q[s] = 0;
  d[s] = 0;
  
  while (x != 1) {
    u = q[m];
    
    for (v = 0; v < n; v++) {
      if (M[u][v] == 0) {
        continue;
      }
      if (d[v] != 101) {
        continue;
      }
      d[v] = d[u] + 1;
      q[++s] = v;
    }
    if (m == n - 1) {
      for (i = 0 ; i < n ; i++) {
        if (d[i] == 101) {
          d[i] = -1;
        }
      }
      x = 1;
    }
    m = m + 1;
  }
  
  for (u = 0; u < n; u++) {
    printf("%d %d\n", u + 1, d[u]);
  }
}

int main() {
  int u, v, k, i, j;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }
  
  for (i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    u--;
    for (j = 0; j < k; j++) {
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }
  
  bfs(0);
  
  return 0;
}
