#include <stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS(void);
void DFS_Visit(int);

int u,k;
int color[N];
int time;
int d[N],f[N];
int n;
int G[N][N];

int main(){
  
  int i,j;
  int Adj[N];  

  scanf("%d",&n);

  if(n < 0 || N < n) return 0;
  
  for(i=0;i < n;i++) {
    for(j=0;j < n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i < n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j < k;j++){
      scanf("%d",&Adj[j]);
      G[u-1][Adj[j]-1] = 1;
    }
  }
  
  DFS();

  for(i=0;i < n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);
  
  return 0;
}

void DFS(void){
  int i;
  
  for(i=0;i < n;i++){
    color[i] = WHITE;
    time = 0;
  }
  
  for(i=0;i < n;i++){
    if(color[i] == WHITE) DFS_Visit(i);
  }
}

void DFS_Visit(int u){
  int i;
  
  color[u] = GRAY;
  time++;

  d[u] = time;
  
  for(i=0;i < n;i++){
    if(color[i] == WHITE && G[u][i] == GRAY) {
      DFS_Visit(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}
