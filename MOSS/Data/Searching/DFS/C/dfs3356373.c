#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int g[N][N],n;
int color[N],d[N],f[N],time;

void visit(int u){
  int v;

  color[u]=GRAY;
  d[u]=++time;
  for(v=0;v<n;v++){
    if(g[u][v]==0) continue;
    if(color[v]==WHITE){
      visit(v);
    }
  }
  color[u]=BLACK;
  f[u]=++time;
}
void dfs(void){
  int u;
  for(u=0;u<n;u++) color[u]=WHITE;
  time=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE) visit(u);
  }
  for(u=0;u<n;u++) printf("%d %d %d\n",u+1,d[u],f[u]);
}
int main(){
  int i,j,k,a,b;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) g[i][j]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&k);
    a--;
     for(j=0;j<k;j++){
       scanf("%d",&b);
       b--;
       g[a][b]=1;
     }
  }

  dfs();

  return 0;

}
