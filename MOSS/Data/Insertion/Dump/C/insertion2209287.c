#include <stdio.h>

void insertion_sort() {
  int N;
  int A[1005];
  int i, j;

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  for (i = 0; i < N; i++) {
    int v = A[i];

    for (j = i - 1; j >= 0 && v < A[j]; j--) {
      A[j + 1] = A[j];
    }
    A[j + 1] = v;

    for (j = 0; j < N; j++) {
      if (j != 0) {
        printf(" ");
      }
      printf("%d", A[j]);
    }
    printf("\n");
  }
}

int main(void) {
  insertion_sort();

  return 0;
}
