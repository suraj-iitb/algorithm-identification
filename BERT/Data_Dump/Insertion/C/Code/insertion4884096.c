#include <stdio.h>

void insertionSort( int a[], int n ) {
  for( int i = 1; i <= n - 1; i++ ) {
    int v = a[i];
    int j = i - 1;
    while( j >= 0 && a[j] > v ) {
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    for( int i = 0; i < n; i++ ) {
      printf( "%d", a[i] );
      if( i != n - 1 ) printf( " " );
    }
    printf( "\n" );
  }
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  int a[n];
  for( int i = 0; i < n; i++ ) {
    scanf( "%d", &a[i] );
    printf( "%d", a[i] );
    if( i != n - 1 ) printf( " " );
  }
  printf( "\n" );
  insertionSort( a, n );

  return 0;
}

