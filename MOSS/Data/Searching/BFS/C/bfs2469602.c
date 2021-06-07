#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
  
int A[N][N], color[N];
int d[N], Q[N+1];
int n, q1 = 0, q2 = 0;
  

void bfs() {
  int i, u;
  for(i = 1; i <= n; i++) {
    color[i] = WHITE;
    d[i] = -1;
  }
  color[1] = GRAY;
  d[1] = 0;
  Q[q1] = 1;
  q1++;
  while(q1 != q2) {
    u = Q[q2];
    q2++;
    for(i = 1; i<= n; i++) {
      if(A[u][i] == 1) {
        if(color[i] == WHITE) {
          color[i] = GRAY;
          d[i] = d[u] + 1;
          Q[q1] = i;
          q1++;
        }
      }
    }
    color[u] = BLACK;
  }
}

  
int main() {
  int u, v, k, i, j;
  
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    Q[i] = -1;
    for(j = 1; j <= n; j++) {
      A[i][j] = 0;
    }
  }
  Q[n+1] = -1;
  
  for(i = 1; i <= n; i++) {
    scanf("%d", &u);
    scanf("%d", &k);
    for(j = 1; j <= k; j++) {
      scanf("%d", &v);
      A[u][v] = 1;
    }
  }
  
  bfs();
  
  for(i = 1; i <= n; i++) {
    printf("%d %d\n", i, d[i]);
  }
  
  return 0;
}
  
  
