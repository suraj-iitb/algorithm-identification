#include <stdio.h>
#define N 100

void dfs(void);
void visit(int);

int G[N][N];
int color[N];
int S[N];
int d[N];
int f[N];
int t=0;
int n=0;

int main(void){
  int u=0,k=0,v=0;
  int i=0,j=0;
  for(i=0; i<N; i++){
    for(j=0; j<N; j++) G[i][j] = 0;
  }
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d%d",&u,&k);
    for(j=0; j<k; j++){
      scanf("%d",&v);
      G[u-1][v-1] = 1;
    }
  }
  dfs();
  for(i=0; i<n; i++) printf("%d %d %d\n",i+1,d[i],f[i]);  
return 0;
}

void dfs(void){
  int u=0;
  for(u = 0; u < n; u++) color[u] = 0;
  for(u = 0; u < n; u++){
    if(color[u] == 0) visit(u);
  }
}

void visit(int u){
  int v=0;
  color[u] = 1;
  d[u] = ++t;
  for(v = 0; v < n; v++){
    if(G[u][v] == 0) continue;
    if(color[v] == 0) visit(v); 
  }
  color[u] = 2;
    f[u] = ++t;
}
