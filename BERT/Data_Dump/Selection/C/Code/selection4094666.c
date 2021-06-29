#include <stdio.h>
#include <stdlib.h>

int main( void ){
  int n, count = 0;
  scanf("%d\n", &n );

  int *a = ( int * )malloc( n * sizeof( int ) );
  for( int i = 0 ; i < n ; i ++ )
    scanf("%d", a + i );

  for( int i = 0; i < n; i ++ ){
    int mini = i;
    for( int j = i + 1; j < n; j ++ ){
      if( a[ j ] < a[ mini ] )
        mini = j;
    }
    if( i != mini ){
      int tmp = a[ mini ];
      a[ mini ] = a[ i ];
      a[ i ] = tmp;
      count ++;
    }
  }
  for( int i = 0; i < n - 1; i ++ )
    printf("%d ", a[ i ] );
  printf("%d\n%d\n", a[ n - 1 ], count );
  return 0;
}
