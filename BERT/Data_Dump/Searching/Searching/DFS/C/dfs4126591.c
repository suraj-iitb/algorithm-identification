#include <stdio.h>

void dfs();
void visit(int);

int n,color[101] = {},d[101],f[101],G[101][101];

int main(){
  int id,i,j;

  scanf("%d",&n);
  
  for(i = 1; i < n+1;i++){
    scanf("%d%d",&G[i][0],&G[i][1]);
    
   for(j = 0;j < G[i][1]; j++){
     scanf("%d",&G[i][2+j]);
    }
  }
  dfs();
  return 0;
}

void dfs(){
  int i;
  
  for(i = 1; i < n+1;i++){
    if(color[i] == 0)visit(i);
  }

  for(i = 1; i < n+1;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
}

void visit(int u){
  int i;
  int static time = 0;
  
  color[u] = -1;
  d[u] = ++time;
  
  for(i = 0; i < G[u][1];i++){
    if(color[G[u][2+i]] == 0)visit(G[u][2+i]);
  }
  color[u] = -2;
  f[u] = ++time;
}

