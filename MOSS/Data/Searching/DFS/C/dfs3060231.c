#include <stdio.h>

void dfs(void);
void visit(int);

int n;
int G[101][101];
int color[101];
int d[101];
int f[101];
int time;
int main (){
  int i,j;
  int u,v,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)G[i][j] = 0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1] = 1;
    }
  }
  
  dfs();
  
  
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
    
  return 0;
}
void dfs(){
  int i;
  for(i=0;i<n;i++){
    color[i] = 0;
  }
  time = 0;
  for(i=0;i<n;i++){
    if(color[i] == 0)visit(i);
  }
}


void visit(int i){
  int m;
  color[i] = 1;
  d[i] = ++time;
  for(m=0;m<n;m++){
    if(G[i][m] == 0)continue;
    if(color[m] == 0)visit(m);
  }
  color[i] = 2;
  f[i] = ++time;
}

