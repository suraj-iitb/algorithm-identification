#include <stdio.h>

main(){
  int A[100];
  int n, flag, j, x, count;

  scanf("%d\n", &n);

  for( j = 0; j < n; j++){
    scanf("%d", &A[j]);
  }

  count = 0;
  flag = 1;

  while( flag ){
    flag = 0;

    for( j = n-1; 1 <= j; j--){
      
      if( A[j] < A[j-1] ){
	
	x = A[j];
	A[j] = A[j-1];
	A[j-1] = x;
	
	count++;
	
	flag = 1;
      
      }

    }

  }

  for( j = 0; j < n; j++){
    if( j == n-1 ) printf("%d\n", A[j]);
    else printf("%d ", A[j]);
  }

  printf("%d\n", count);

  return 0;

}
