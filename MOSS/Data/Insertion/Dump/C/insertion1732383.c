#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *, int);
int main(){
  int *A;
  int k;
  int n;
  scanf("%d", &n);
  A = (int *)malloc(sizeof(int) * n);
  for(k = 0; k < n; k++)
    scanf("%d", &A[k]);
//  printf("\n");
  insertionSort(A, n);
  free(A);
  return 0;
}

void insertionSort(int* A, int N){
  int i, k;
  printf("%d", A[0]);
  for(k = 1; k < N; k++)
    printf(" %d", A[k]);
  printf("\n");
  for(i = 1; i < N; i++){
    int j;
    for(j = i - 1; j >= 0 && A[j] > A[j + 1]; j--){
      int tmp = A[j];
      A[j] = A[j + 1];
      A[j + 1] = tmp;
    }
    printf("%d", A[0]);
    for(k = 1; k < N; k++)
      printf(" %d", A[k]);
    printf("\n");
  }
}
