#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 101
int n,color[N],i,time,d[N],f[N],G[N][N] = {};
 void dfs(void);
void visit(int);
int main(){
  int i,j,k,u,v;
  
  scanf("%d",&n);
  for(i=1;i<=n;i++) {
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      G[u][v] = 1;
     }
  }
   for(u=1;u<=n;u++) color[u] = WHITE;
  dfs();
  
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
 void dfs(){
      int u;

  for(u=1;u<=n;u++) if(color[u] == WHITE) visit(u);
  }

void visit(int u){
 int v;
  color[u] = GRAY;
  d[u] = ++time;
  
  for(v=1;v<=n;v++) {
    if(color[v] == WHITE && G[u][v]) visit(v);
  }
  color[u] = BLACK;
  f[u] = ++time;
}
