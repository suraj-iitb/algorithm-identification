#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 200

int n, time = 0;
int color[N], d[N], f[N], A[N][N];


void  DFSVisit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  
  
  for(v=1; v <= n; v++){
    if((color[v]== WHITE) && (A[u][v] == 1)) DFSVisit(v);
  }
   
  color[u] = BLACK;
   f[u] = ++time;
   
}

void DFS(){
  int u;
  for(u=1; u <= n; u++){
    color[u] = WHITE;
  }

  for(u=1; u <= n; u++){
    if(color[u] == WHITE) DFSVisit(u);
  }
  
}





int main(void){
  int i, j,  u, v, k; 
  
  scanf("%d", &n);
  
  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      A[i][j] = 0;
    }
  }
  
  for(i=1; i<=n; i++){
    scanf("%d%d", &u, &k);
    for(j=1; j<=k; j++){
      scanf("%d", &v);
      A[u][v] = 1;
    }
    
  }
  
  DFS();
  
  for(i=1; i<=n; i++) printf("%d %d %d\n", i, d[i], f[i]);
  
return 0;
}
