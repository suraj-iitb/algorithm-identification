#include<stdio.h>
#include<stdlib.h>
void visit(int**,int*,int*,int*,int,int);

int t = 0;

int main(){
  int i,j,n,u,k,v,*d,*f,*color,**G;
  scanf("%d",&n);
  G = malloc((n+1) * sizeof(int *));
  d = malloc((n+1) * sizeof(int));
  f = malloc((n+1) * sizeof(int));
  color = malloc((n+1) * sizeof(int));
  for(i=1;i<=n;i++){
    G[i] = malloc((n+1) * sizeof(int));
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      G[i][j] = 0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u][v] = 1;
    }
  }
  for(i=1;i<=n;i++){
    color[i]=1;
  }
  for(i=1;i<=n;i++){
    if(color[i]==1){
      visit(G,d,f,color,n,i);
    }
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

void visit(int **G,int *d,int *f,int *color,int n,int u){
  int i;
  color[u] = 0;
  d[u] = ++t;
  for(i=1;i<=n;i++){
    if(G[u][i]==1){
      if(color[i] == 1){
        visit(G,d,f,color,n,i);
      }
    }
  }
  color[u] = -1;
  f[u] = ++t;
}

