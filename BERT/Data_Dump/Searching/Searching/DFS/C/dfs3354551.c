#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[MAX][MAX];
int color[MAX], d[MAX], f[MAX], time = 0;
/*再帰、for 文に注意。3 から 2 に戻るときに color[2] に BLACK が代入される前に、まだ終っていない for 文に注目すると、v が 4 のときに 17行目が成り立つから、再び再帰。*/
void dfs_visit(int u){
  int v;
  
  color[u] = GRAY;
  d[u] = ++time;
  for(v = 0; v < n; v++){  
    if(M[u][v] == 0) continue;
    if(color[v] == WHITE){
      dfs_visit(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}
void dfs(){
  int u;

  for(u = 0; u < n; u++) color[u] = WHITE;
  for(u = 0; u < n; u++){
    if(color[u] == WHITE) dfs_visit(u);
  }
  for(u = 0; u < n; u++) printf("%d %d %d\n", u + 1, d[u], f[u]);
}


int main(){
  int i, j, k, u, v;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++)
      M[i][j] = 0;
  }

  for(i = 0; i < n; i++){
    scanf("%d %d", &u, &k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }
  dfs();
  
  return 0;
}

