#include<stdio.h>
#define WHITE 1
#define BLACK 0
#define GLAY 3
int g[120][120];
int d[120],f[120],color[120],k[120];
int time,u,v;

void DFSVisit(int u){
  int i;
  color[u] = GLAY;
  d[u] = ++time;
  for(i = 0;i < k[u];i++){
    if(color[g[u][i]] ==  WHITE){
      DFSVisit(g[u][i]);
       }
       }
  color[u] = BLACK;
  f[u] = ++time;
}

void DFS(int x){
  int i;
  for(i = 1;i <=x; i++){
    color[i] = WHITE;
    time = 0;
      }
  for(i = 0; i < x;i++){
    if(color[i] == WHITE){
      DFSVisit(i);
    }
  }
  }

main(){
  int i,j,l,n;
  scanf("%d",&n);

  for(i = 0;i < n; i++){
    scanf("%d%d",&u,&l);
    k[u] = l;
    for(j = 0;j < k[u];j++){
      scanf("%d",&v);
      g[u][j] = v;
    }
  }


      DFS(n);
    for(i = 1; i <=n;i++){
      printf("%d %d %d\n", i,d[i],f[i]);
    }
    return 0;
  }
