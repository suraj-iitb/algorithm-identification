#include<stdio.h>

#define whi 0
#define gra 1
#define bla 2
#define M 100

int T[M][M],color[M],d[M],ti=0,f[M];
int n;

void visit(int u){
  int v;
  
  color[u] = gra;
  d[u] = ++ti;
  for(v=0; v<n; v++){
    if(T[u][v] == 0)continue;
    if(color[v] == whi){
      visit(v);
    }
  }
  color[u] = bla;
  f[u] = ++ti;
}

void dfs(void){
  int i;
  
  for(i=0; i<n; i++){
    color[i] = whi;
  }
    
  for(i=0; i<n; i++){
    if(color[i] == whi)visit(i);
  }
}

int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      T[i][j] = 0;
    }
  }

  for(i=0; i<n; i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0; j<k; j++){
      scanf("%d",&v);
      v--;
      T[u][v] = 1;
    }
  }

  dfs();

  for(i=0; i<n; i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}

