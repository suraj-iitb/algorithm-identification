#include <stdio.h>
#include <stdlib.h>
int compare( const void * a, const void * b){ return *( int *)a - *( int *)b; }
int search( int *a, int length, int key ){
  int low = 0, high = length - 1;
  while( 1 ){
    if( low > high ) return 0;
    int mid = low + ( high - low ) / 2;
    if( a[ mid ] < key ){
      low = mid + 1;
      continue;
    }
    else if( a[ mid ] == key ) return 1;
    else {
      high = mid - 1;
      continue;
    }
  }
}

int main( void ){
  int n;
  scanf("%d\n", &n );
  int *s = ( int * ) malloc ( n * sizeof( int ) );
  for( int i = 0; i < n; i ++ )
    scanf("%d", s + i );

  //qsort( ( void * )s, n, sizeof( int ), compare );                                                                          

  int q;
  scanf("%d\n", &q );
  int count = 0;
  for( int i = 0; i < q; i ++ ){
    int t;
    scanf("%d", &t );
    count += search( s, n, t );
  }
  printf( "%d\n", count );
  return 0;
}
