#include <stdio.h>

void trace(int A[], int N) {
  int i;
  for (i=0; i<N; i++) {
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void bubbleSort(int A[], int N) {
  int j, count = 0, i = 0;
  int flag = 1;
  while (flag) {
    flag = 0;
    for (j = N-1; j > i; j--) {
      if (A[j] < A[j-1]) {
        int tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        count++;
      }
    }
    i++;
  }
  trace(A, N);
  printf("%d\n", count);
}

int main() {
  int N, i, j;
  int A[100];

  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  bubbleSort(A, N);



  return 0;
}
