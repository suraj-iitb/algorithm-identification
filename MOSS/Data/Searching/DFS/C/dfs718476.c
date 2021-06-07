#include <stdio.h>
#define N 101
#define WHITE 0
#define BLACK 1
#define GRAY 2

void DFSvisit(int);
void DFS(void);

int vertex[N];
int color[N];
int d[N];
int f[N];
int e[N];
int time;
int n;
int G[N][N];

int main(void){

  int i, j;


  scanf("%d",&n);

  for(i = 1;i <= n;i++){
    scanf("%d %d", &vertex[i], &e[i]);
    for(j = 1;j <= e[i];j++)
      scanf("%d", &G[vertex[i]][j]);
  }

  DFS();
  
  for(i = 1;i <= n;i++)
    printf("%d %d %d\n",vertex[i], d[vertex[i]], f[vertex[i]]);
   
  return 0;
}


void DFS(){

  int u;

  for(u = 1;u <= n;u++)
    color[u] = WHITE;

  time = 0;

  for(u = 1;u <= n;u++){
    if(color[u] == WHITE)
      DFSvisit(u);
  }

}

void DFSvisit(int u){

  int v;

  color[u] = GRAY;
  time++;
  d[u] = time;

  for(v = 1;v <= e[u];v++){
    if(G[u][v] && (color[G[u][v]] == WHITE))
      DFSvisit(G[u][v]);
  }

  color[u] = BLACK;
  f[u] = ++time;
}
