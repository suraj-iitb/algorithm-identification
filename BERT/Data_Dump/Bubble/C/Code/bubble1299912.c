#include "stdio.h"

main(){

  int A[100], i=0, j, c=0, n, swap, flag = 1;

  scanf("%d", &n);

  for(j=0 ; j<n ; j++){
    scanf("%d", &A[j]);
  }

  while(flag==1){

    flag = 0;

    for(j=(n-1) ; j>=i+1 ; j--){

      if(A[j] < A[j-1]){

	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;

	flag = 1;
	c++;
      }

    }
    i++;
  }

  for(j=0 ; j<n ; j++){
  printf("%d", A[j]);
  if(j<(n-1)) printf(" ");
  else{printf("\n");
   }
  }
  printf("%d\n", c);
  return 0;
}
