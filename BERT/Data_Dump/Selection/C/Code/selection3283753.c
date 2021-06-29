#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *, int); // N 個の要素を含む 0-オリジンの配列 A


int main() {
  int i, N, *A;
  
  scanf( "%d" , &N );
  A = (int *)malloc(N * sizeof(int));
  for( i=0; i<N; i++ ) scanf( "%d" , &A[i] );
  selectionSort(A, N);
  
  return 0;
}


void selectionSort(int *A, int N) {
  int i, j, minj, temp, count=0;
  
  for ( i=0; i<N; i++ ) {
    minj = i;
    for ( j=i; j<N; j++ ) if ( A[j] < A[minj] ) minj = j;
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if ( minj != i ) count++;
  }
  for ( j=0; j<(N-1); j++ ) printf( "%d " , A[j] );
  printf( "%d\n%d\n" , A[N-1] , count );
}

