#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int); // N 個の要素を含む 0-オリジンの配列 A


int main() {
  int i, N, *A;
  
  scanf( "%d" , &N );
  A = (int *)malloc(N * sizeof(int));
  for( i=0; i<N; i++ ) scanf( "%d" , &A[i] );
  bubbleSort(A, N);
  
  return 0;
}


void bubbleSort(int *A, int N) {
  int flag=1, i=0, j, temp, count=0; // flag=1 : 逆の隣接要素が存在する
  
  while ( flag ) { // flag != 0
    flag = 0;
    for ( j=(N-1); j>i; j-- ) {
      if ( A[j] < A[j-1] ) {
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        count++;
        flag = 1;
      }
    }
    i++;
  }
  for ( j=0; j<(N-1); j++ ) printf( "%d " , A[j] );
  printf( "%d\n%d\n" , A[N-1] , count );
}

