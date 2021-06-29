#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int bubbleSort(int A[], int N) {
  int i, j;
  int flag = 1, count = 0;

  for (i = 0; flag; i++) {
    flag = 0;
    for (j = N - 1; j > i; j--) {
      if (A[j-1] > A[j]){
        swap(&A[j-1], &A[j]);
        count++;
        flag = 1;
      }
    }
  }
  return count;
}

int main() {
  int i;
  int N, A[100], count;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  count = bubbleSort(A, N);

  for (i = 0; i < N; i++) {
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", count);

  return 0;
}
