#include <stdio.h>

#define M 100
#define WHITE 1
#define BLACK 0
#define GRAY 2

void dfs(void);

void visit(int);


int n,time;

int tyouten[M][M],color[M],d[M],f[M];

int main(){

  int i,j,k,u,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    for(j=0;j<n;j++) tyouten[i][j]=0;

  }

  for(i=0;i<n;i++){

    scanf("%d%d",&u,&k);

    for(j=0;j<k;j++){

      scanf("%d",&v);

      tyouten[u-1][v-1]=1;

    }

  }

  dfs();

  return 0;

}


void dfs(){

  int u;

  for(u=0;u<n;u++) color[u]=WHITE;

  time=0;

  for(u=0;u<n;u++){

    if(color[u]==WHITE) visit(u);

  }

  for(u=0;u<n;u++) printf("%d %d %d\n",u+1,d[u],f[u]);

}


void visit(int u){

  int v;

  color[u]=GRAY;

  d[u]=++time;

  for(v=0;v<n;v++){

    if(tyouten[u][v]==0) continue;

    if(color[v]==WHITE) visit(v);

  }

    color[u]=BLACK;
    f[u]=++time;

}
