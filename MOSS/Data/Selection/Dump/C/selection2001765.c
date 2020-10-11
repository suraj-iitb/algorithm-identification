#include<stdio.h>
int main(){

  int i,j,k,n,A[101],min,count;

  count = 0;

  scanf("%d", &n );

  for ( i = 0 ; i < n ; i++ ){
    scanf("%d", &A[i] );
  }

  for ( i = 0 ; i < n ; i++ ){

    min = A[i];
    k = i;
    
    for ( j = i ; j < n ; j++ ){
      if ( A[j] < min ) {
	min = A[j];
	k = j;
      }
    }

    if ( i != k ) {
      count += 1;
    }
    
    A[k] = A[i];
    A[i] = min;

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
