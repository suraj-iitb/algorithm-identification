#include <stdio.h>

void display(int A[], int N) {
  for(int i = 0; i < N; i++) {
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int N) {
  int v, j;
  for(int i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    display(A, N);
  }
}

int main() {
  int n, A[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  display(A, n);
  insertionSort(A, n);
  return 0;
}
