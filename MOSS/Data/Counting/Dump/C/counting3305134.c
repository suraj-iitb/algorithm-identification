#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  for( i= 0 ; i <= VMAX ; i++ ){
    C[i] = 0;
  }
  for( i = 0 ; i < n ; i++ ){
    scanf( "%hu", &A[i + 1] );
    C[A[i + 1]]++;

  }


  for( i = 0 ; i < VMAX ; i++ ){
    C[i + 1] = C[i + 1] + C[i];
  }


  for( j = 0 ; j < n ; j++ ){
    B[C[A[j+1]]] = A[j+1];
    C[A[j+1]]--;
  }


  for( i = 1 ; i <= n ; i++ ){
    printf( "%d", B[i] );
    if( i != n ){
      printf( " " );
    }
  }
  printf( "\n" );


  return 0;
}
