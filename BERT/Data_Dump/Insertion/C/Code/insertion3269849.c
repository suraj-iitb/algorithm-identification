#include <stdio.h>
#include <stdlib.h> // malloc

void insertionSort(int *, int); // N個の要素を含む0-オリジンの配列A

int main() {
  int N, *A, i;
  
  scanf( "%d" , &N );
  A = (int *)malloc(N * sizeof(int));
  for( i=0; i<N; i++ ) scanf( "%d" , &A[i] );
  insertionSort(A, N);
  
  return 0;
}

void insertionSort(int *A, int N) {
  int i, j, k, v;

  for ( k=0; k<(N-1); k++ ) printf( "%d " , A[k] );
    printf( "%d\n" , A[N-1] );
  for ( i=1; i<=(N-1); i++ ) {
    v = A[i];
    j = i-1;
    while( (j >= 0) && (A[j] > v) ) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for ( k=0; k<(N-1); k++ ) printf( "%d " , A[k] );
    printf( "%d\n" , A[N-1] );
  }
}

