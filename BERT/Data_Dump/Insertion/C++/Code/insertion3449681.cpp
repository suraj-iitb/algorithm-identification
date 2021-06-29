#include<stdio.h>

void insertionSort(int A[], int N) {
  for ( int i = 0; i < N; i++ ) {
    int v = A[i];
    int j = i - 1;
    while ( j >= 0 && v < A[j]) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    for ( int i = 0; i < N; i++ ) {
      if ( i ) printf(" ");
      printf("%d", A[i]);
    }
    printf("\n");
  }
}



int main() {
  int N;
  int A[100];

  scanf("%d", &N);
  for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]);

  insertionSort(A, N);

  return 0;
}

