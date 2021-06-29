#include<stdio.h>
int main(){

  int i,j,k,n,v,A[1001];
  
  scanf("%d", &n );

  for ( i = 0 ; i < n ; i++ ){
    scanf("%d", &A[i] );
  }
    
  for ( i = 0 ; i < n ; i++ ){

    v = A[i];
    
    for ( j = 0 ; j < i ; j++ ){
      if ( v <= A[j] ){
	for ( k = i ; k > j ; k-- ){
	  A[k] = A[ k - 1 ];
	}
	A[j] = v;
	break;
      }
    }

    for ( j = 0 ; j < n ; j++ ){
      if ( j == n - 1 ) {
	printf("%d\n", A[j] );
      } else {
	printf("%d ", A[j] );
      } 
    }

  }

  return 0;

}
