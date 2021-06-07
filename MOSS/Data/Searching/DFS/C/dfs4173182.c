#include<stdio.h>

#define N 105
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int AM[N][N];
int color[N], d[N], f[N], time;

void DFS(void);
void DFS_visit(int);

int main(){
  int i, j, u, k, v;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    for(j = 0 ; j < n ; j++){
      AM[i][j] = 0;
    }
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      v--;
      AM[u][v] = 1;
    }
  }

  DFS();

  return 0;
}


void DFS_visit(int u){
  int i;

  color[u] = GRAY;
  d[u] = ++time;
  for(i = 0 ; i < n ; i++){
    if(AM[u][i] ==  0) continue;
    if(color[i] == WHITE){
      DFS_visit(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}
void DFS(){
  int i;
  for(i = 0 ; i < n ; i++){
    color[i] = WHITE;
  }

  time = 0;

  for(i = 0 ; i < n ; i++){
    if(color[i] == WHITE) DFS_visit(i);
  }

  for(i = 0 ; i < n ; i++){
    printf("%d %d %d\n",i+1, d[i],f[i]);
  }
}

