#include<stdio.h>
int main(){

  int i,j,k,n,A[101],count;

  count = 0;
  
  scanf("%d", &n );
  
  for ( i = 0 ; i < n ; i++ ){
    scanf("%d", &A[i] );
  }

  for ( i = 0 ; i < n - 1 ; i++ ){
    
    for ( j = 0 ; j < n - 1 ; j++ ){

      if ( A[j] > A[ j + 1 ] ) {
	k = A[j];
	A[j] = A[ j + 1 ];
	A[ j + 1 ] = k;
	count += 1;
      }
      
    }
    
  } 

  for ( i = 0 ; i < n ; i++ ){

    if ( i < n - 1 ){
      printf("%d ", A[i] );
    } else {
      printf("%d\n", A[i] );
    }
  }

  printf("%d\n", count );

  return 0;
  
}
