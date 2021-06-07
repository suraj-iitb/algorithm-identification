#include<stdio.h>

#define N 102
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int color[N], d[N], f[N], time, M[N][N];

void visit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i=1; i <= n; i++){
    if(color[i] == WHITE && M[u][i] == 1) visit(i);
  }
  color[u] = BLACK;
  f[u] = ++time;
}

void DFS(){
  int i;
  for(i=1; i <= n; i++){
    color[i] = WHITE;
  }
  time = 0;
  for(i=1; i <= n; i++){
    if(color[i] == WHITE) visit(i);
  }
}

int main(){
  int x, i, j, y, num;
  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      M[i][j] = 0;
    }
    scanf("%d",&num);
    scanf("%d",&x);
    if(x != 0){
      for(j = 1; j <= x; j++){
	scanf("%d",&y);
	M[num][y] = 1;
      }
    }
  }
  DFS();
  for(i=1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return 0;
}
