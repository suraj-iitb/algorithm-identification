#include <stdio.h>

#define GRAY 1
#define WHITE 0
#define BLACK 2
#define N 100

int n, Adj[N][N];
int color[N], d[N], f[N], time;
/*
colorは頂点の訪問状態、dは最初に訪問した発見時刻
fは隣接リストを調べ終えた完了時刻
再帰プログラム
*/
void visit(int u) {
  int v;
  color[u] = GRAY;
  d[u] = ++time;//最初の訪問
  for (v = 0; v < n; v++) {
    if (Adj[u][v] == 0) continue;
    if (color[v] == WHITE) {
      visit(v);
    }
  }
  color[u] = BLACK; //ここで黒にする
  f[u] = ++time;
}

void dfs() {
  int u;
  for (u = 0; u < n; u++) color[u] = WHITE;

  time = 0; //初期化

  for (u = 0; u < n; u++) {
    //未訪問のuを起点に深さ優先探索
    if (color[u] == WHITE) visit(u);
  }
  for (u = 0; u < n; u++) {
    printf("%d %d %d\n", u+1, d[u], f[u]);
  }
}


int main() {
  int i, j, u, v, k;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) Adj[i][j] = 0;
  }

  for (i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    u--;
    for (j = 0; j < k; j++) {
      scanf("%d", &v);
      v--;
      Adj[u][v] = 1;
    }
  }

dfs();

  return 0;
}

