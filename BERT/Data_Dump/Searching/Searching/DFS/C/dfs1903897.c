#include <stdio.h>


#define N 100
#define BLACK 0
#define WHITE 1
#define GRAY 2

int adj[N][N],n,time,f[N],color[N],d[N];

void dfs(void){

  int i;

  for (i=0;i<n;i++){

    color[i]=WHITE;
  }

    time =0;

  for(i=0;i<n;i++){
    if (color[i]==WHITE) visit(i);
  }

  for(i=0;i<n;i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}


visit(int u){

  int v;

  color[u]=GRAY;
  d[u]=++time;

  for(v=0;v<n;v++){
    if(adj[u][v]==0) continue;
  if(color[v]==WHITE) visit(v);
  }
  color[u]=BLACK;
  f[u]=++time;

}

int main(){

  int i,j,b,c,a;

    scanf("%d",&n);

    for(i=0;i<n;i++){
      for(j=0;j<n;j++){

	adj[i][j]=0;
      }
    }

    for(i=0;i<n;i++){
      scanf("%d%d",&b,&c);
      for(j=0;j<c;j++){

      scanf("%d",&a);
      adj[b-1][a-1]=1;


    }
    }

    dfs();

    return 0;
  }
