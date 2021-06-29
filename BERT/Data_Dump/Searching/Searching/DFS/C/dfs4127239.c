#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);

int G[N][N];//Graph
int color[N];
int S[N];//Stack
int d[N];//discover
int f[N];//finish
int t = 0;//time
int n = 0;

int main(){

  int u = 0, k = 0, v = 0;
  int i = 0, j = 0;
 
  //initialize
  for(i = 0; i < N; i++){
    
    for(j = 0; j < N; j++){
      G[i][j] = 0;
    }
    
  }

  //scan
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      G[u-1][v-1] = 1;
    }
    
  }

  dfs();
  
  //print
  for(i = 0; i < n; i++){

    printf("%d %d %d\n",i+1,d[i],f[i]);
    
  }
  
  return 0;

}

void dfs(void){
  
  int u = 0;
  
  for(u = 0; u < n; u++){
    
    color[u] = WHITE;
    
  }
  
  for(u = 0; u < n; u++){

    if(color[u] == WHITE)visit(u);
    
  }
  
}

void visit(int u){

  int v = 0;
  
  color[u] = GRAY;
  d[u] = ++t;
  for(v = 0; v < n; v++){

    if(G[u][v] == 0)continue;
    
    if(color[v] == WHITE){
      
      visit(v);
      
    }
    
  }
  color[u] = BLACK;
    f[u] = ++t;
}

