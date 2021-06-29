#include <stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void dfs_visit(int);

int color[MAX],M[MAX][MAX],n;
int d[MAX],f[MAX];
int time;

int main(){
  int u,k,v;
  int i,j;

  scanf("%d",&n);

  for (i = 0;i < n;i++){
    scanf("%d %d",&u,&k);

    u--;
    
    for (j = 0;j < k;j++){
      scanf("%d",&v);

      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  for (i = 0;i < n;i++){
    printf("%d %d %d\n",i + 1,d[i],f[i]);
  }
  return 0;
}

void dfs(void){
  int i;

  for (i = 0;i < n;i++)
    color[i] = WHITE;

  for (i = 0;i < n;i++)
    if (color[i] == WHITE)
      dfs_visit(i);
}

void dfs_visit(int u){
  int v;
  
  color[u] = GRAY;
  d[u] = ++time;

  for (v = 0;v < n;v++){
    if (M[u][v] && color[v] == WHITE)
      dfs_visit(v);
  }

  color[u] = BLACK;
  f[u] = ++time;
}

