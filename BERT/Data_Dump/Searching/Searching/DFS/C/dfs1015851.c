#include<stdio.h>
#define N 105
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, time = 0;
int color[N], d[N], f[N], array[N][N];

void DFS(){
  int i, time;
  for(i = 1; i < n+1; i++){
      color[i] = WHITE;
  }

  for(i = 1; i < n+1; i++){
    if(color[i] == WHITE) DFSvisit(i);
  }
}

void DFSvisit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  
  for(i = 1; i < n+1; i++){
    if((color[i] == WHITE) && (array[u][i] == 1)) DFSvisit(i);
  }
  color[u] = BLACK;
  f[u] = ++time;
}

main(){

  scanf("%d", &n);

  int i, u, v, j, e;
  for(i = 1; i < n+1; i++){
    for(j = 1; j < n+1; j++){
      array[i][j] = 0;
    }
  }

  for(i = 1; i < n+1; i++){
    scanf("%d%d", &u, &e);
    for(j = 1; j < e+1; j++){
      scanf("%d", &v);
      array[i][v] = 1;
    }
  }

  DFS();
  
  for(i = 1; i < n+1; i++){
    printf("%d ", i);
    printf("%d ", d[i]);
    printf("%d\n", f[i]);
  }
  return 0;
}
