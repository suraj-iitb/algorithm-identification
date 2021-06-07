#include <stdio.h>
typedef struct ver{
  int e[101];
  int se;
  int color;
} ver;
  
int n,u;
int time;
int d[101];
int f[101];
ver g[101];

void visit(int u){
  int v,w;
  g[u].color=1;
  d[u] = ++time;
  for(v=1;v<=g[u].se;v++){
    w=g[u].e[v];
    if(g[w].color == 0){
      visit(w);
    }
  }
  g[u].color = 2;
  f[u] = ++time;
}

void dfs(){
  int u;
  for(u=1;u<=n;u++){
    g[u].color = 0;
  }
  time = 0;
  for(u=1;u<=n;u++){
    if(g[u].color==0){
      visit(u);
    }
  }
}




int main(){
  int i,j,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    g[u].se=k;
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      g[u].e[j]=v;
    }
  }

  dfs();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  return 0;
}
