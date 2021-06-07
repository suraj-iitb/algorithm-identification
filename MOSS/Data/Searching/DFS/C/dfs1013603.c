#include<stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
void DFSVisit(int);
void DFS(void);
int G[MAX][MAX];
int D[MAX];
int F[MAX];
int color[MAX];
int n;
int time;
main(){
  int i, j, m, k, value;
  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){

      G[i][j] = 0;

    }
  }

  for(i = 1; i <= n; i++){

    scanf("%d %d", &k, &m);

    for(j = 1; j <= m; j++){

      scanf("%d",&value);

      G[i][value] = 1;
    }
  }
 
  DFS();

  for(i = 1; i <= n; i++)
    {
      printf("%d %d %d\n", i, D[i], F[i]);
    }

 return 0;

}




void DFS(void){
  int u;

  for( u = 1; u <= n; u++ ){
    color[u] = WHITE;
  }

  time = 0;

 for( u = 1; u <= n; u++ ){
   if( color[u] == WHITE )
     DFSVisit(u);

  }
}

void DFSVisit(int u){
  int v;

  color[u] = GRAY;

  time++;
 
  D[u] = time;

  for(v = 1; v <= n ; v++){

    if(G[u][v] == 1 && color[v] == WHITE)
      DFSVisit(v);
  }
  color[u] = BLACK;
  F[u] = ++time;
}
