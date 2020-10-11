#include <stdio.h>

int selectionSort(int A[], int N) {
  int swap = 0;
  for (int i = 0; i < N - 1; i++) {
    int min = i;
    int flag = 0;
    for (int j = i + 1; j < N; j++) {
      if (A[j] < A[min]) {
        min = j;
        flag = 1;
      }
    }
    if (flag) {
      int tmp = A[i];
      A[i] = A[min];
      A[min] = tmp;
      swap++;
    }
  }
  return swap;
}

void printArr(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(void) {
  int N;
  scanf("%d", &N);
  int A[N];
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  int swap = selectionSort(A, N);
  printArr(A, N);
  printf("%d\n", swap);

  return 0;
}
