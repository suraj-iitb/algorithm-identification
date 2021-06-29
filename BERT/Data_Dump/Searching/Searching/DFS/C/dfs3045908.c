#include <stdio.h>

#define N 101

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs();
void visit(int);

int A[N][N] = {0};
int color[N] = {0};
int d[N] = {0};
int f[N] = {0};
int num ,time;

int main(){
  int inum, jnum, count, i, j;
  
  scanf("%d", &num);
  
  for(i = 1; i <= num; i++){
    scanf("%d %d", &inum, &count);  
    for(j = 1; j <= count; j++){
      scanf("%d", &jnum);
      A[inum][jnum] = 1;
    }
  }
  
  dfs();
  
  for(i = 1; i <= num; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  
  
  return 0;
}

void dfs(){
  int i;

  time = 0;
  
  for(i = 1; i <=num; i++){
    if(color[i] == WHITE){
      visit(i);
    }
  }
}

void visit(int u){
  int i;

  //printf("num %d visit", u);
  
  color[u] = GRAY;
  d[u] = ++time;

  for(i = 0; i <=num; i++){
    if(A[u][i] == 1 && color[i] == WHITE){
      visit(i);
    }
  }

  color[u] = BLACK;
  f[u] = ++time;
}

