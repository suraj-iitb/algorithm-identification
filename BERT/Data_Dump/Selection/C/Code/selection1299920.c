#include <stdio.h>

main(){
  int A[100];
  int i, j, n, x, minj, count;

  scanf("%d", &n);

  for( i = 0; i < n; ++i){
    scanf("%d", &A[i]);
  }

  count = 0;

  for( i = 0; i < n; i++){
    minj = i;

    for( j = i; j < n; j++){

      if( A[j] < A[minj] ) minj = j;

    }
    
    if( A[i] != A[minj] ){
    x = A[i];
    A[i] = A[minj];
    A[minj] = x;

    count++;

    }

  }

  for( i = 0; i < n; i++){
    if( i == n-1 ) printf("%d\n", A[i]);
    else printf("%d ", A[i]);
  }

  printf("%d\n", count);

  return 0;

}
