#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n;
  scanf("%d\n", &n );

  int *a = ( int * )malloc( n * sizeof( int ) );

  for( int i = 0; i < n; i ++ ){
    scanf("%d", a + i );
  }

for( int k = 0; k < n - 1; k ++ )
      printf("%d ", a[ k ] );
    printf("%d\n", a[ n - 1 ] );
    
  for( int i = 1; i < n; i ++ ){
    int key = a[ i ];
    int j = i - 1;
    while( j >= 0 && a[ j ] > key ){
      a[ j + 1 ] = a[ j ];
      j --;
    }
    a[ j + 1 ] = key;
    for( int k = 0; k < n - 1; k ++ )
      printf("%d ", a[ k ] );
    printf("%d\n", a[ n - 1 ] );
  }
  return 0;
}
