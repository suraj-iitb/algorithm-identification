#include <stdio.h>
#define MAX 100

int count = 0;

void print_array(int *A, int N) {
  int i;
  for(i = 0; i < N - 1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[i]);
}

void selectionSort(int *A, int N) {
  int i, j, minj, v;
  for(i = 0; i < N; i++) {
    minj = i;
    for(j = i; j < N; j++) {
      if(A[j] < A[minj]) minj = j;
    }
    if(minj != i) {
      v = A[i];
      A[i] = A[minj];
      A[minj] = v;
      count++;
    }
  }
}

int main() {
  int n, i, a[MAX];
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  selectionSort(a, n);
  print_array(a, n);
  printf("%d\n", count);
  return 0;
}

