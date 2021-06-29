#include <stdio.h>

#define MAX 100
#define WHITE 0
#define BLACK 1
#define GRAY 2

void dfs();
void visit(int);

int num, time;
int graph[MAX][MAX];
int d[MAX];
int f[MAX];
int color[MAX];


int main(){

  int i, j, inum, jnum, line;

  scanf("%d", &num);

  for(i = 0; i < num; i++){

    for(j = 0; j < num; j++){

      graph[i][j] = 0;

    }

    scanf("%d %d", &inum, &jnum);

    for(j = 0; j < jnum; j++){

      scanf("%d", &line);

      graph[inum - 1][line - 1] = 1;

    }

  }

  dfs();
  
  for(i = 0; i < num; i++){

    printf("%d %d %d\n", (i + 1), d[i], f[i]);

  }

  return 0;

}

void dfs(){

  int u, k;

  for(u = 0; u < num; u++){
   
    color[u] = WHITE;
 
  }

  time = 0;

  for(u = 0; u < num; u++){
      
    if(color[u] == WHITE)
      visit(u);

  }
  
}

void visit(int u){
  
  int v;

  color[u] = GRAY;

  d[u] = ++time;

  for(v = 0; v < num; v++){

    if(graph[u][v] == 0)
      continue;

    if(color[v] == WHITE)
      visit(v);

  }

  color[u] = BLACK;

  f[u] = ++time;

}
