#include <stdio.h>
#define N 100
#define WHITE 1
#define BLACK 2
#define GRAY 3

int time,color[N],f[N],d[N],adj[N][N];

void visit(int u,int n){
  int v;
  color[u]=GRAY;
  d[u]=++time;
  for(v=0;v<n;v++){
    if(adj[u][v]==0) continue;
    if(color[v]==WHITE) visit(v,n);
  }
  color[u]=BLACK;
  f[u]=++time;
}

void dfs(int n){
  int u;
  for(u=0;u<n;u++){
    color[u]=WHITE;
  }

  time=0;

  for(u=0;u<n;u++){
    if(color[u]==WHITE) visit(u,n);
  }

  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int n,i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++) for(j=0;j<n;j++) adj[i][j]=0;

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    if(k!=0){
      for(j=1;j<=k;j++){
	scanf("%d",&v);
	v--;
	adj[u][v]=1;
      }
    } 
  }
    
  dfs(n);
  
  return 0;
}

