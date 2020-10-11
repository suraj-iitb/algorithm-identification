#include <stdio.h>

void swap ( int *x, int *y ) {
  int temp = *y;
  *y = *x;
  *x = temp;
}

void trace ( int A[], int N ) {
  for ( int i = 0; i < N ; i++ ) {
    printf ( "%d", A[i] );
    if ( i == N - 1 )
      break;
    printf( " " );
  }
  putchar ( '\n' );
}

void selection ( int A[], int N, int cnt) {
  for ( int i = 0; i < N - 1; i++ ) {
    int minj = i;
    for ( int j = i; j < N; j++ ) {
      if ( A[j] < A[minj] ) {
        minj = j;
      }
    }
    if ( i != minj )
      cnt++;
    swap ( &A[minj], &A[i] );
  }
  trace ( A, N );
  printf ( "%d\n", cnt );
}


int main ( void ) {
  int N; int cnt = 0;
  int A[100];
  scanf ( "%d", &N);
  for ( int i = 0; i < N; i++ ) {
    scanf ( "%d", &A[i] );
  }
  selection ( A, N, cnt );
}

