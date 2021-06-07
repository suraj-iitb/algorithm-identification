#include<stdio.h>

#define N 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int G[N+1][N+1];
int time;
int color[N+1];
int d[N+1],f[N+1];

void visit(int u){
  int i;
  
  color[u] = GRAY;
  d[u] = ++time;
  for(i=1;i<=n;i++){
    if(G[u][i]==1 && color[i]==WHITE) visit(i);
  }
  color[u] = BLACK;
  f[u] = ++time;
}

void dfs(){
  int i;

  for(i=1;i<=n;i++){    
    color[i] = WHITE;
  }
  time = 0;
  for(i=1;i<=n;i++){
    if(color[i]==WHITE) visit(i);
  }
}

int main(){

  int i,j,k;
  int flag;

  scanf("%d",&n);

  int Adj[n+1][n+2];

  for(i=1;i<=n;i++){
    scanf("%d",&Adj[i][0]);
    scanf("%d",&Adj[i][1]);
    for(j=0;j<Adj[i][1];j++){
      scanf("%d",&Adj[i][j+2]);
    }
  }

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      G[i][j]=0;
      for(k=0;k<Adj[i][1];k++){
	if(j==Adj[i][k+2]){
	  G[i][j]=1;
	  break;
	}
      }
    }
  }

  dfs();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}

