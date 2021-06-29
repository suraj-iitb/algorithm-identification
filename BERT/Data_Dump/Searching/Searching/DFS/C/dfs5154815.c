#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, mat[N][N];
int t,color[N],d[N],f[N];

void visit(int);
void dfs();

int main(){
  int u,v,k;
  int i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){mat[i][j]=0; }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      mat[u][v]=1;
    }
  }
  dfs();
  
  return 0;
}

void visit(int u){
  int v;
  
  color[u]=GRAY;
  d[u]=++t;
  for(v=0;v<n;v++){
    if(mat[u][v]==0)continue;
    if(color[v]==WHITE)visit(v);
  }  
  color[u]=BLACK;
  f[u]=++t;
}

void dfs(){
  int u;

  for(u=0;u<n;u++)color[u]=WHITE;
  t=0;

  for(u=0;u<n;u++)if(color[u]==WHITE){visit(u);}
  for(u=0;u<n;u++){printf("%d %d %d\n",u+1,d[u],f[u]); }
  
}

