#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(int);
void visit(int);

int V,u,a[101][101],d[101],f[101],time,color[101];

int main(){
  int i,j,v,k;

  scanf("%d",&V);
  for(i=1;i<=V;i++){
     for(j=1;j<=V;j++){
       a[i][j]=0;
     }
  }
  for(i=1;i<=V;i++){
    scanf("%d%d",&u,&k);
    color[u]=WHITE;
    if(k!=0){
      for(j=1;j<=k;j++){
	scanf("%d",&v);
	a[i][v]=1;
      }
    }
  }
  for(i=1;i<=V;i++){
  dfs(i);
  }
  for(i=1;i<=V;i++){
    printf("%d %d ",i,d[i]);
    printf("%d\n",f[i]);
    }
  
  return 0;
}

void dfs(int u){
  for(u=1;u<=V;u++){
    color[u]=WHITE;
  }
  time=0;
  for(u=1;u<=V;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
}

void visit(int u){
  int i;
  color[u]=GRAY;
  d[u] = ++time;
  for(i=1;i<=V;i++){
    if(a[u][i]==1 && color[i]==WHITE){
      visit(i);
    }
  }
  color[u]=BLACK;
  f[u] = ++time;
}
  

