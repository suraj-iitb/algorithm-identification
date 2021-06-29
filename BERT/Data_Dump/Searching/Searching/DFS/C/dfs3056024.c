#include <stdio.h>
#define W 0
#define G 1
#define B 2

int n,M[100][100];
int color[100],d[100],f[100],time;

void visit(int);
void dfs();

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  dfs();

  return 0;
      
}

void visit(int u){
  int i;
  color[u] = G;
  d[u]  = ++time;
  for(i=0;i<n;i++){
    if(M[u][i]==0) continue;
    if(color[i] == W){
      visit(i);
    }
  }
  color[u] = B;
  f[u] = ++time;
}

void dfs(){
  int i;
  for(i=0;i<n;i++) color[i] = W;
  time=0;

  for(i=0;i<n;i++){
    if(color[i]==W) visit(i);
  }
  
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

