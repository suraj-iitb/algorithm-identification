#include <stdio.h>

void trace(int A[], int N) {
  int i;
  for (i=0; i<N; i++) {
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void selectionSort(int A[], int N) {
  int i, j, minj, count = 0;
  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (minj != i) count++;
    int tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
  }
  trace(A, N);
  printf("%d\n", count);
}

int main() {
  int N, i, j;
  int A[100];

  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  selectionSort(A, N);

  return 0;
}
