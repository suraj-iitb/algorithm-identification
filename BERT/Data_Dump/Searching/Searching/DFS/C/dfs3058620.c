// Depth First Search
#include <stdio.h>

#define MAX 101

// 頂点の訪問状態をcolorで表す //
#define BLACK  2
#define GRAY 1
#define WHITE 0

// タイムスタンプd[v]: v を最初に発見した発見時刻を記録する
// タイムスタンプf[v]: v の隣接リストを調べ終えた完了時刻を記録する
// 隣接行列M:頂点iから頂点jまで辺があるとき1
int time, n, d[MAX], f[MAX], color[MAX], M[MAX][MAX];

// 再帰による深さ優先探索
void visit(int u){
  int i;
  
  color[u] = GRAY; // 頂点uを訪問
  time++;
  d[u] = time;   // 訪問した発見時刻を記録
  
  for(i=0; i < n; i++){
    if(M[u][i] == 0) continue;
    if(color[i] == WHITE) visit(i);
  }
  color[u] = BLACK; // 頂点uの隣接リストの調査終了
  time++;
  f[u] = time;    // 調べ終えた完了時刻を記録
  // time++;
}

void dfs(){
  int u;

  // すべての頂点のcolorをwhiteにする //
  for(u=0; u < n; u++){
    color[u] = WHITE; // 初期化
  }
  time = 0; // 初期化
  
  for(u=0; u < n; u++){
    if(color[u] == WHITE)visit(u);
  }
  for(u=0; u < n; u++){
    printf("%d %d %d\n", u+1, d[u], f[u]);
  }
}

int main(){
  int i, j, k, row, col;
  scanf("%d", &n);

  // 隣接行列Mを初期化
  for(i=0; i < n; i++){
    for(j=0; j < n; j++){
      M[i][j] = 0;
    }
  }
  
  for(i=0; i < n; i++){
    scanf("%d%d", &row, &k);
    for(j=0; j < k; j++){
      scanf("%d", &col);
      M[row-1][col-1] = 1;
    }
  }

  dfs();

  return 0;
}
