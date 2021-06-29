#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {

  int N;
  scanf("%d", &N);

  int* A = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < N; i++) {
    int v = A[i], j;
    for (j = i - 1; j >= 0 && A[j] > v; j--) {
      A[j + 1] = A[j];
    }
    A[j + 1] = v;

    for (int k = 0; k < N; k++) {
      if (k) printf(" ");
      printf("%d", A[k]);
    }
    printf("\n");
  }

  return 0;
}
