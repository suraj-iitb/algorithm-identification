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

void bubble ( int A[], int N, int cnt ) {
  for ( int i = 0; i < N - 1; i++ ) {
    for (int j = 0; j < N - 1 - i; j++ ) {
      if ( A[j] > A[j+1] ) {
        swap ( &A[j], &A[j+1]);
        cnt++;
      }
    }
  }
  trace ( A, N );
  printf( "%d\n", cnt );
}

int main ( void ) {
  int i, N; int cnt = 0;
  int A[100];
  scanf ( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    scanf ( "%d", &A[i] );
  }
  bubble ( A, N, cnt );

}

