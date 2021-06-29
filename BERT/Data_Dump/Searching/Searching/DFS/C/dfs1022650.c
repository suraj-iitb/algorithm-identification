#include <stdio.h>
#define N 101
#define WHITE -1
#define BLACK 1
#define GRAY 0
int color[N], n, G[N][N];
int d[N], f[N];
int time = 0;

void DFSvisit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i = 1; i <= n; i++){
      if(G[u][i] == 1){
        if(color[i] == WHITE) DFSvisit(i);
      }
  }
  color[u] = BLACK;
  f[u] = ++time;
}
 
void DFS(void){
  int i, j;
  for(i = 1; i <= n; i++){
        color[i] = WHITE;
        time = 0;
  }
  for(i = 1; i <= n; i++){
        if(color[i] == WHITE) DFSvisit(i);
  }
}
 

int main() {
    int i, j;
    int u, v, k;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d", &u, &k);
        for (j = 0; j < k; j++) {
            scanf("%d", &v);
            G[u][v] = 1;
        }
    }

    DFS();

    for (i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, d[i], f[i]);
    }
    return 0;
}
