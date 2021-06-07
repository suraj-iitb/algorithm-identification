#include<stdio.h>
#define WHITE 1
#define BLACK 0
#define GLAY 3
#define N 102
int g[N][N],d[N],f[N],color[N],k[N];
int time,u,v,n;
 
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
 
void DFS(){
  int i;
  for(i = 1;i <=n; i++){
    color[i] = WHITE;
  }
    time = 0;
  for(i = 0; i < n;i++){
    if(color[i] == WHITE){
        DFSVisit(i);
    }
  }
  }
 
int main(){
  int i,j,l;
  scanf("%d",&n);
 
  for(i = 0;i < n; i++){
    scanf("%d",&u);
    scanf("%d",&l);
    k[u] = l;
    for(j = 0;j < k[u];j++){
      scanf("%d",&v);
      g[u][j] = v;
    }
  }
 
 
      DFS();
    for(i = 1; i <=n;i++){
      printf("%d %d %d\n", i,d[i],f[i]);
    }
    return 0;
  }
