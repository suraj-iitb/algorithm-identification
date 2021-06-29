#include <stdio.h>

#define SIZE 128

void insertionSort(int *A, int N);

int main(void){
  int i, N, A[SIZE] = {0};
  scanf("%d", &N);
  for (i = 0; i < N; i++)
    scanf("%d", &A[i]);

  // output step 0
  for (i = 0; i < N; i++) {
    printf("%d", A[i]);
    if(i != N - 1)
      printf(" ");
  }
  printf("\n");
    
  insertionSort(A, N);
  return 0;
}

void insertionSort(int *A, int N){
  int i, j, k, v;
  for (i = 1; i <= N - 1; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    // output each step
    for (k = 0; k < N; k++) {
      printf("%d", A[k]);
      if(k != N - 1)
	printf(" ");
    }
    printf("\n");
  }
}
