#include<stdio.h>


int G[101][101], A[101], B[101], n;

void f(int a, int b){
  int i;
  A[a] = b;
  for(i = 1; i <= B[a]; i++){
    if(b + 1 < A[G[a][i]]) f(G[a][i], b + 1);
  }
}

int main(){
  int i, j, m;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    A[i] = 100000000;
    scanf("%d", &m);
    scanf("%d", &B[m]);

    for(j = 1; j <= B[m]; j++) scanf("%d", &G[m][j]);
  }

  f(1, 0);

  for(i = 1; i <= n; i++){
    if(A[i] == 100000000) A[i] = -1;
  }

  for(i = 1; i <= n; i++) printf("%d %d\n", i, A[i]);

  return 0;
}
