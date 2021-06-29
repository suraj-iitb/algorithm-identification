#include <stdio.h>

void trace(int A[], int N){
  int i;
  for (i = 0; i < N; i++) {
    if (i > 0) printf(" "); //put space
    printf("%d",A[i]);
  }
  printf("\n");
}

void InsertionSort(int A[], int N){
  int j, i, v;
  for (i = 1; i < N ; i++){
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    trace(A, N);
  }
}

int main() {
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
    }

    trace(A, N);
    InsertionSort(A, N);

  return 0;
}

