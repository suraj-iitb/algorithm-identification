#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

  int u;
  int k;
  int v;
int Adj[101][101];
int color[101];
int d[101];
int f[101];
int time;

void visit(int u,int n){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i=0;i<n;i++){
    if(Adj[u][i]==1){
    if(color[i] == WHITE){
      visit(i,n);
    }
    }
  }
  color[u] == BLACK;
  f[u]=++time;
}


void dfs(int n){
  int i;
  for(i=0;i<n;i++){
    color[i]=WHITE;
      }
  for(i=0;i<n;i++){
    if(color[i]==WHITE){
      visit(i,n);
    }
  }
}

int main(){
  int n,i,j;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      if(k!=0){
        Adj[i][v-1]=1;
    }
    }
  }

  dfs(n);
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    printf("%d ",d[i]);
    printf("%d",f[i]);
    printf("\n");
    }
  return 0;
}

