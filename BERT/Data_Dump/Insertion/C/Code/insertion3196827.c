#include <stdio.h>

void trace ( int A[], int N ) {
  for ( int i = 0; i < N; i++ ) {
    printf ( "%d", A[i] );
    if ( i == N - 1 )
      break;
    printf( " " );
  }
  putchar ( '\n' );
}

void insertion ( int A[], int N ) {
  for ( int i = 1; i < N; i++ ) {
    int key = A[i]; int j;
    j = i - 1;
    while ( j >= 0 && A[j] > key ) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    trace ( A, N );
  }
}

int main ( void ) {
  int N, i;
  int A[100];
  scanf ( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    scanf ( "%d", &A[i] );
  }
  trace ( A, N );
  insertion ( A, N );
}

