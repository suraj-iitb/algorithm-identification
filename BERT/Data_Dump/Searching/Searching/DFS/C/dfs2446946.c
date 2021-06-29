#include<stdio.h>
#include<stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2;
void DFS(void);
void visit(int);
int n,**M,*color,*d,*f,time=0;
int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  M = (int**)malloc(sizeof(int*) * n);     // dynamic allocation start
  for(i=0; i<n+1; i++){                    // *
    M[i] = (int*)malloc(sizeof(int) * n);  // *
  }                                        // *
  color = (int*)malloc(sizeof(int) * n);   // *
  d = (int*)malloc(sizeof(int) * n);       // *
  f = (int*)malloc(sizeof(int) * n);       // dynamic allocation end
  for(i=0; i<n; i++){    // initialization start
    color[i] = WHITE;    // *
    d[i] = f[i] = 0;     // *
    for(j=0; j<n; j++){  // *
      M[i][j] = 0;       // *
    }                    // *
  }                      // initialization end
  for(i=0; i<n; i++){     // input data start
    scanf("%d%d",&u,&k);  // *
    for(j=0; j<k; j++){   // *
      scanf("%d",&v);     // *
      M[u-1][v-1] = 1;    // *
    }                     // *
  }                       // input data end
  DFS();  // Depth First Search
  return 0;
}
void DFS(void){
  int u;
  for(u=0; u<n; u++){
    if(color[u] == WHITE){
      visit(u);
    }
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
void visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for(v=0; v<n; v++){
    if(M[u][v] != 0 && color[v] == WHITE){
      visit(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;      // visit completed
}
