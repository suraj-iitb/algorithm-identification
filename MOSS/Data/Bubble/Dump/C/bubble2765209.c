#include <stdio.h>

int bubbleSort(int A[], int N) {
  int times = 0;
  for (int i = N - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (A[j] > A[j + 1]) {
        int tmp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = tmp;
        times++;
      }
    }
  }
  return times;
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
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  int t = bubbleSort(A, N);
  printArr(A, N);
  printf("%d\n", t);

  return 0;
}
