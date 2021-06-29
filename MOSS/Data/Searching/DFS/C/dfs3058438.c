#include<stdio.h>
#define N 501
#define WHITE 0
#define GRAY 1
#define BLACK 2

static const int INFTY = (1<<21);

int n,M[N][N];
int color[N],d[N],f[N],t;

void visit(int u){
  int v;
  color[u]=GRAY;
    d[u]=++t;
  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(color[v]==WHITE){
      visit(v);
    }
  }
  color[u]=BLACK;
  f[u]=++t;
}

void dfs(){
  int i,u;
  for(i=0;i<n;i++) color[i]=WHITE;
  t=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE) visit(u);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

int main(){
  int u,k,v; 
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) M[i][j]=0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j= 0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  dfs();

  return 0;
}
