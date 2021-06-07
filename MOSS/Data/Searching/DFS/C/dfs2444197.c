#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
 
void dfs(void);
void visit(int);
 
int G[N][N],n,d[N],f[N],color[N],time;
 
int main(){
   int i,j,k,u,v;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      G[i][j] = 0;
    }
  }
  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    u=u-1;
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      v=v-1;
      G[u][v] = 1;
    }
  }
  dfs();
  return 0;
}
  void dfs(){
    int i;
    for(i = 0; i < n; i++) color[i] = WHITE;
    time = 0;
    for(i =0 ; i < n; i++){
      if(color[i] == WHITE) visit(i);
    }
    for( i = 0; i < n; i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
  }
  void visit(int u){
    int i;
    color[u] = GRAY; 
    d[u] = ++time;
    for(i = 0; i < n; i++){
      if(G[u][i] == 0) continue;
      if(color[i] == WHITE){
    visit(i);
      }
    }
    color[u] = BLACK;
    f[u] = ++time;
  }
