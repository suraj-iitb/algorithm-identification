#include <stdio.h>

#define N 100
#define WHITE 0
#define BLACK 1
#define GRAY 2

int G[N][N], d[N], f[N], color[N], time=0;

void DFS(int n, int u){
  int v;

  color[u] = GRAY;

  d[u] = ++time;

  for(v = 0; v < n; v++)
    if(G[u][v] == 1 && color[v] == WHITE) DFS(n, v);

  color[u] = BLACK;
  f[u] = ++time;

}

int main(){
  int n, i, j, u, k, v;

  scanf("%d", &n);

  //initialize
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      G[i][j] = 0;

  for(i = 0; i < n; i++){
    scanf("%d %d", &u, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      G[u - 1][v - 1] = 1;
    }
  }

  for(i = 0; i < n; i++)
    color[i] = WHITE;

  for(i = 0; i < n; i++)
    if(color[i] == WHITE) DFS(n, i);

  for(i = 0; i < n; i++)
    printf("%d %d %d\n", i+1, d[i], f[i]);

  return 0;
}
