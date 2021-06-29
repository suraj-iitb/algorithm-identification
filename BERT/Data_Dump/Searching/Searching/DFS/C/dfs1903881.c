#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, color[101], d[101], f[101],time, a[101][101];  

void visit(int u){
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=0; i<n; i++){
    if(a[u][i]==0)continue;
    if(color[i]==WHITE)visit(i);
  }
  color[u] = BLACK;
  f[u]=++time;
}

void dfs(){
  int i;
  for(i=0; i<n; i++){
    color[i]=WHITE;
  }
  time=0;
  for(i=0; i<n; i++){
    if(color[i]==WHITE)visit(i);
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  
}
  
  

int main(){
  int i, j, k,u, v;

  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    scanf("%d %d",&u,&k);
    for(j=0; j<k; j++){
      scanf("%d", &v);
      a[u-1][v-1]=1;
    }
  }

  dfs();
  return 0;
}
