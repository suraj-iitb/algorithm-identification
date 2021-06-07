#include <stdio.h>
#define N 101
#define white 0
#define gray 1
#define black 2
int n, spt = 0, time = 0;
int A[N][N] = {0}, nt[N] = {0}, color[N], stack[N], d[N], f[N];

void push(int u) {
  stack[++spt] = u;
}

void pop(void) {
  --spt;
}

int next(int u) {
  for (int v = nt[u]; v <= n; ++v) {
    nt[u] = v + 1;
    if (A[u][v]) return v;
  }
  return -1;
}

void dfs(int u) {
  int v;
  push(u);
  color[u] = gray;
  d[u] = ++time;

  while (spt > 0) {
    u = stack[spt];
    v = next(u);
    if (v != -1) {
      if (color[v] == white) {
        color[v] = gray;
        d[v] = ++time;
        push(v);
      }
    }
    else {
      pop();
      color[u] = black;
      f[u] = ++time;
    }
  }
}

void dfs_init(void) {
  for (int i = 1; i <= n; ++i) color[i] = white;
  for (int u = 1; u <= n; ++u) {
    if (color[u] == white) {
      dfs(u);
    }
  }
}

void print(void) {
  for (int u = 1; u <= n; ++u) {
    if (color[u] == black) {
      printf("%d %d %d", u, d[u], f[u]);
      putchar('\n');
    }
  }
}

int main(void) {
  int u, k, v;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &u, &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &v);
      A[u][v] = 1;
    }
  }
  dfs_init();
  print();
}

