#include<stdio.h>
#define N 100
#define White 0
#define Black 2
#define Gray 1


int GX[N][N],x,color[N],time,d[N],f[N];

void visit(int u){
  int v;
  color[u]=Gray;
  d[u]=++time;
  for(v=0;v<x;v++){
    if(GX[u][v]==0) continue;
    if(color[v]==White) visit(v);
  }
  color[u]=Black;
  f[u]=++time;
}

void dfs(){
  int u;
  for(u=0;u<x;u++) color[u]=White;
  time=0;
  for(u=0;u<x;u++){
    if(color[u]==White) visit(u);
  }
  for(u=0;u<x;u++) printf("%d %d %d\n",u+1,d[u],f[u]);
}

int main(){

  int i,j,a,b,c,v,g;

  scanf("%d",&x);

  for(i=0;i<x;i++){
    for(j=0;j<x;j++){
      GX[i][j]=0;
    }
  }

  for(i=0;i<x;i++){
    scanf("%d",&v);
    scanf("%d",&g);
    v--;
    for(j=0;j<g;j++){
      scanf("%d",&a);
      a--;
      GX[v][a]=1;
    }
  }

  dfs();
  return 0;
}
