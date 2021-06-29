#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, count = 0;
  scanf("%d\n", &n );
  int *a = ( int * )malloc( n * sizeof( int ) );
  for(int i = 0; i < n; i ++ )
    scanf("%d", a + i );

  for( int i = 0; i < n; i ++){
    for( int j = n - 1; j > i; j -- ){
      if( a[ j - 1 ] > a[ j ] ){
        int tmp = a[ j ];
        a[ j ] = a[ j - 1 ];
        a[ j - 1 ] = tmp;
        count ++;
      }
    }
  }
  for( int i = 0; i < n - 1 ; i ++ )
    printf("%d ", a[ i ] );
  printf("%d\n%d\n", a[ n - 1 ], count );
  return 0;
}
