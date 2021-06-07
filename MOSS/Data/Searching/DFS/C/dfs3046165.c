#include<stdio.h>

#define WHITE 1
#define GRAY 2
#define BLACK 3

int V,color[101],d[101],f[101],time,a[101][101];

void visit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++ time;
  for(i=1;i<=V;i++){
    if(a[u][i]==1 &&color[i] == WHITE){
      visit(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}

void dfs(void){
  int u;
  for(u=1;u<=V;u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u=1;u<=V;u++){
    if(color[u] == WHITE){
      visit(u);
    }
  }
}
int main(){
  int i,j,n,id,k;
  scanf("%d",&V);
  for(i=1;i<=V;i++){
    for(j=1;j<=V;j++){
      a[i][j] =0;
    }
  }
  for(i=1;i<=V;i++){
    scanf("%d%d",&id,&n);
    if(n!=0){
      for(j=0;j<n;j++){
        scanf("%d",&k);
        a[i][k] = 1;
      }
    }
  }
  for(i=1;i<=V;i++){
    dfs();
  }
  for(i=1;i<=V;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

