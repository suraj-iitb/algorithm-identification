#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, A[N][N];
int C[N],B[N], D[N], e;

void dfs(int);

void dfs2();

int main(){
  int i, j, a, b, c;
  
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d", &a, &b);
    a--;
    for(j = 0; j < b; j++){
      scanf("%d", &c);
      c--;
      A[a][c] = 1;
    }
  }

  dfs2();

  return 0;
}

void dfs(int a){
  int b;
  C[a] = GRAY;
  B[a] = ++e;
  for(b = 0; b < n; b++){
    if(A[a][b] == 0) continue;
    if(C[b] == WHITE){
      dfs(b);
    }
  }
  C[a] = BLACK;
  D[a] = ++e;
}


void dfs2(){
  int i;
  for(i = 0; i < n; i++){
    C[i] = WHITE;
  }

  e = 0;
  for(i = 0; i < n; i++){
    if(C[i] == WHITE )
      dfs(i);
  }
  for(i = 0; i < n; i++){
    printf("%d %d %d\n", i+1, B[i], D[i]);
  }

}

