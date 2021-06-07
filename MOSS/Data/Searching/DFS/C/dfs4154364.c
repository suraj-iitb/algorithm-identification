#include<stdio.h>

#define WHITE 1
#define GRAY 2
#define BLACK 3

int d[101],f[101],time=0,colar[101],M[101][101],n;

void visit(int u){
  int v;

  colar[u]=GRAY;
  d[u]=++time;

  for(v=1;v<=n;v++){
    if(M[u][v]==0)continue;
    if(colar[v]==WHITE)
      visit(v);
  }
  colar[u]=BLACK;
  f[u]=++time;
}

int main(){
  int i,j,k,u,v;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    colar[i]=WHITE;
    for(j=1;j<=n;j++){
      M[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    if(k==0)continue;
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      M[u][v]=1;
    }
  }

  for(u=1;u<=n;u++){
    if(colar[u]==WHITE)
      visit(u);
  }

  for(u=1;u<=n;u++){
    printf("%d %d %d\n",u,d[u],f[u]);
  }

  return 0;
}

