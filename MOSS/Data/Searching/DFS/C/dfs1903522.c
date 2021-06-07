#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
void init(void);
void print(void);
void dfs(void);
void dfs_s(int);

int n, time;
int graph[N][N], color[N], d[N], f[N];

int main() {
  int i, j, l, m, in;

  init();

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &l, &m);
    for (j = 0; j < m; j++) {
      scanf("%d", &in);
      graph[l - 1][in - 1] = 1;
    }
  }

  dfs();
  print();

  return 0;
}
void dfs(void) {
  int i, j;
  
  for (i = 0; i < n; i++) {
    if (color[i] == WHITE) dfs_s(i);
  }
  
  return ;
}
void dfs_s(int u) {
  int i, j;
  
  color[u] = GRAY;
  d[u] = ++time;
  
  for (i = 0; i < n; i++) {
    if (graph[u][i] == 1 && color[i] == WHITE) {
      dfs_s(i);
    }
  }
  
  color[u] = BLACK;
  f[u] = ++time;
}
  

void init(void) {
  int i, j;

  time = 0;
  for (i = 0; i < N; i++) {
    color[i] = WHITE;
    for (j = 0; j < N; j++) {
      graph[i][j] = 0;
    }
  }
  return ;
}
void print(void) {
  int i, j;
  
  for (i = 0; i < n; i++) {
    printf("%d %d %d\n", i + 1, d[i], f[i]);
  }
  return ;
}
