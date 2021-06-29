#include <stdio.h>

#define N 101

int M[N][N];
int n;
int d[N], v[N], visited[N], time;

void DFS();
void visit(int);

int main(){
  int i, j, x, y, z;

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      M[i][j] = 0;
    }
  }

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d %d", &x, &y);

    for(j = 0; j < y; j++){
      scanf("%d", &z);
      M[x-1][z-1] = 1;
    }
  }

  DFS();

  for(i = 0; i < n; i++)
    printf("%d %d %d\n", i+1, d[i], v[i]);

  return 0;
}

void DFS(){
  int i;
  for(i = 0;i < n; i++){
    if(visited[i] == 0)
      visit(i);
  }
}

void visit(int r){
  int i;
  visited[r] = 1;
  d[r] = ++time;

  for(i = 0; i < n; i++){
    if(M[r][i] == 1 && visited[i] == 0)
      visit(i);
  }
  visited[r] = 2;
  v[r] = ++time;
}
