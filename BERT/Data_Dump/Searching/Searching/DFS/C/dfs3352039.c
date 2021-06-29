#include <stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

void pet(int);
int A[MAX][MAX],color[MAX],d[MAX],f[MAX],count,n;

int main(){
  int i,j,k,m,l;

  scanf("%d",&n);
  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++){
      A[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d",&m);
    scanf("%d",&k);
    for(j = 0; j < k; j++){
      scanf("%d",&l);
      A[m][l] = 1;
    }
  }

  for(i = 0; i <= n; i++){
    color[i] = WHITE;
  }

  for(i = 0; i < n; i++){
    if(color[i+1] == WHITE) pet(i+1);
  }

  for(i = 0; i < n; i++){
    printf("%d %d %d\n",i+1,d[i+1],f[i+1]);
  }

  return 0;
}

void pet(int p){
  int e;

  color[p] = GRAY;
  d[p] = ++count;
  for(e = 0; e < n; e++){
    if(A[p][e+1] == 0) continue;
    if(color[e+1] == WHITE){
      pet(e+1);
    }
  }
  color[p] = BLACK;
  f[p] = ++count;
}

