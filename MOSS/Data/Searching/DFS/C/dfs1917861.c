#include <stdio.h>
#define N 200
#define WHITE 0
#define BLACK 1
#define GRAY 2
void dfs(void);
void visit(int);
int time=0;
int d[N];
int f[N];
int color[N];
int n;
int array[N][N];
int main(){
  int i,j,u,k,vk;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      array[i][j]=0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=1;j<=k;j++){
       scanf("%d",&vk);
       array[i][vk]=BLACK;
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
    }
void dfs(void){
  int u;
  for(u=1;u<=n;u++){
    color[u]=WHITE;
  }
    time=0;
   for(u=1;u<=n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
}
void visit(int u){
  int v;
  color[u]=GRAY;
  d[u]=++time;
  for(v=1;v<=n;v++){
    if(color[v]==WHITE && array[u][v]==BLACK){
      visit(v);
    }
  }
    color[u]=BLACK;
    f[u]=++time;
}
