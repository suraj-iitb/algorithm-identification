#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void countingSort(int *A, int *B, int k, int n){
  int i, j, C[VMAX];
  for (i = 0; i <= k; i++){
    C[i] = 0;
  }
   /* C[i] に i の出現数を記録する */
   for (j = 1; j <= n; j++){
     C[A[j]]++;
   }
   for (i = 1; i <= k; i++){
     C[i] = C[i] + C[i - 1];
   }
   for (j = n; j >= 1; j--){
     B[C[A[j]]] = A[j];
     C[A[j]]--;
   }
   return;
}

int main(){
  int *A, *B;
  int C[VMAX+1];
  int n, i, j, k = 0;

  scanf("%d", &n);

  A = (int *)malloc(sizeof(int)*n);
  B = (int *)malloc(sizeof(int)*n);

  for(i = 1; i <= n; i++){
    scanf("%hu", &A[i]);
    if (k <= A[i]) {k = A[i];}
  }

  countingSort(A, B, k, n);

  printf("%hu", B[1]);
  for (i = 2; i <= n; i++){
    printf(" %hu", B[i]);
  }
  printf("\n");

  return 0;
}
