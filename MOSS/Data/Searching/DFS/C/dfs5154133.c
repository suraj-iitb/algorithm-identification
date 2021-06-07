#include <stdio.h>
#include <stdlib.h>

#define WHITE 1
#define BLACK 2
#define GRAY 3

typedef struct{
  int A[105];
}GRAGH;

int D[105],F[105];
int color[105];
int n;
GRAGH list[105];
int timee = 0;

void visit(int u){
  int i;
  color[u] = GRAY;
  D[u] = ++timee;
  for(i = 0;list[u].A[i];i++){
    if(color[list[u].A[i]] == WHITE)visit(list[u].A[i]);
  }
  color[list[u].A[i]] == BLACK;
  F[u] = ++timee;
}

void DFS(GRAGH *G){
  int i;
  for(i = 1; i <= n;i++){
    color[i] = WHITE;
  }
  for(i = 1; i <= n; i++){
    if(color[i] == WHITE)visit(i);
  }
}
  

int main(){
  int i,j,k;
  int x,y,z;

  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    scanf("%d %d",&x,&y);
    k = 0;
    for(j = 1; j <= y;j++){
      scanf("%d",&z);
      list[x].A[k++] = z;
    }
  }

  DFS(list);

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n",i,D[i],F[i]);
  }

  return 0;
}

  

