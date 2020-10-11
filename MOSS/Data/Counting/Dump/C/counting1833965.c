#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  scanf("%d", &n);
  int *A;
  A = (int *)malloc(sizeof(int) * n + 1);
  int max = 0, i;
  for(i = 1; i < n + 1; i++){
    scanf("%d", &A[i]);
    if(A[i] > max)
      max = A[i];
  }
  int *C;
  C = (int *)malloc(sizeof(int) * max + 1);
  for(i = max - 1; i >= 0; i--)
    C[i] = 0;
  for(i = n; i > 0; i--){
    C[A[i]]++;
    //    printf("%d/%d ", A[i], C[A[i]]);
  }
  for(i = 1; i < max + 1; i++){
    //    printf(".%d ", C[i]);
    C[i] += C[i - 1];
    //    printf("_%d ", C[i]);
  }
  int *B;
  B = (int *)malloc(sizeof(int) * n + 1);
  //  for(i = n + 1; i > 0; i--)
  //    B[i] = 0;
  for(i = n; i > 0; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(i = 1; i < n; i++)
    printf("%d ", B[i]);
  printf("%d\n", B[i]);
  free(A), free(B), free(C);
  return 0;
}
