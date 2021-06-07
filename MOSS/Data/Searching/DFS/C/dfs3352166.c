#include <stdio.h>
#define MAX 101
#define WHITE -1
#define GRAY -2
#define BLACK -3

int time;
int d[MAX];
int f[MAX];
int color[MAX];
int n;
int C[MAX][MAX];

void DFS();
void Visit(int);

int main(){
  int i,j,c,I,J;

  for(i=1; i <= n; i++){
    for(j=1; j <= n; j++){
      C[i][j] = 0;
    }
  }

  scanf("%d",&n);

  for(i=1; i <= n; i++){
    scanf("%d",&I);
    scanf("%d",&c);
    for(j=1; j <= c; j++){
      scanf("%d",&J);
      C[I][J] = 1;
    }
  }

  DFS();

  for(i=1; i <= n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}

void DFS(void){
  int i;
  for(i=1; i <= n; i++){
    color[i] = WHITE;
  }
  time = 0;
  for(i=1; i <= n; i++){
    if(color[i] == WHITE){
      visit(i);
    }
  }
}

void visit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i=1; i <= n; i++){
    if(C[u][i] == 1){    
      if(color[i] == WHITE){
	visit(i);
      }
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}

