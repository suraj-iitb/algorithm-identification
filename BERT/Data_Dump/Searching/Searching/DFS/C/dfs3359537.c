#include<stdio.h>

#define MAX 101

#define WHITE 0
#define GRAY 1
#define BLACK 2



int n,color[MAX],time,m[MAX][MAX],f[MAX],d[MAX];


void visit(int u){
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=1;i<=n;i++){
    if(m[u][i]==GRAY && color[i]==WHITE){
      visit(i);
    }
  }
  color[u]=BLACK;
  f[u]=++time;
}


void DFS(){
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


int main(){
  int i,j,u,k,x;

  
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      m[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&x);
      m[u][x]=1;
    }
  }
  
  DFS();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}

