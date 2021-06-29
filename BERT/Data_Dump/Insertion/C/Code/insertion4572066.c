#include <stdio.h>

void insertionSort(int A[], int N) {
  int i, j;
  for (i = 1; i < N; i++) {
    j = i;
    while(j > 0 && A[j-1] > A[j]) {
      swap(&A[j-1], &A[j]);
      j--;
    }
    trace(A, N);
  }
} 

void swap(int *num_large, int *num_small) {
  int tmp;
  tmp = *num_large;
  *num_large = *num_small;
  *num_small = tmp;
}

void trace(int A[], int N) {
  int i;
  for (i = 0; i < N; i++) {
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main() {
  int A[100], N, i;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  trace(A, N);
  insertionSort(A, N);

  return 0;
}
