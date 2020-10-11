#include <stdio.h>
#define MAX 1000

void print_array(int *A, int N) {
  int i;
  for(i = 0; i < N - 1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[i]);
}

void insertionSort(int *A, int N) {
  int i, j, v;
  print_array(A, N);
  for(i = 1; i < N; i++) {
    v = A[i];
    for(j = i - 1; j >= 0 && A[j] > v; j--) {
      A[j+1] = A[j];
    }
    A[j+1] = v;
    print_array(A, N);
  }
}

int main() { 
  int a[MAX], n, i;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  insertionSort(a, n);
  return 0;
}

