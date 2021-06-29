#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int *A,*B;
  int C[VMAX + 1];
  int n,i,j;

  scanf("%d",&n);

  A = (int *)malloc(sizeof(int) * n);
  if(A == NULL) exit(0);
  B = (int *)malloc(sizeof(int) * n);
  if(B == NULL) exit(0);

  for(i = 0;i <= VMAX;i++){
    C[i] = 0;
  }

  /* 数をカウントする */
  for(i = 0;i < n;i++){
    scanf("%d",&A[i + 1]);
    C[A[i + 1]]++;
  }

  /* i以下の数も足す */
  for(i = 1;i <= VMAX;i++){
    C[i] = C[i] + C[i - 1];
  }

  for(j = 1;j <= n;j++){
    B[C[A[j]]] = A[j]; /* Bにコピーする */
    C[A[j]]--;
  }

  for(i = 1;i <= n;i++){
    if(i > 1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}
