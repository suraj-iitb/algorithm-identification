#include <stdio.h>
#define MAX 100
#define WHITE -1
#define GRAY -2
#define BLACK -3

int color[MAX];
int d[MAX],f[MAX],n,time,a[MAX][MAX];

void visit(int u){
  int i;
  
  color[u] = GRAY;
  d[u] = ++time;
  for(i = 0; i < n; i++){
    if(a[u][i] == 0){
      continue;
    }
    if(color[i] == WHITE){
      visit(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}


void dfs(){
  int i,u;
  for(u = 0; u < n; u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u = 0; u < n; u++){
    if( color[u] == WHITE ){
      visit(u);
    }
  }
  for(i = 0; i < n; i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

}


int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      a[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      a[i][v-1] = 1;
    }
  }

  dfs();

  
  return 0;
}
