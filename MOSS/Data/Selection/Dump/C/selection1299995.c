#include "stdio.h"

main(){

  int i, j, minj, n, c=0, swap, A[100];

  scanf("%d", &n);

 for(i=0 ; i<n ; i++){
    scanf("%d", &A[i]);
  }

 for(i=0 ; i<n ; i++){

   minj = i;

   for(j=i ; j<n ; j++){
     if(A[j]<A[minj]){
 minj = j;
     }
   }

   if(A[i] != A[minj]){
   swap = A[i];
   A[i] = A[minj];
   A[minj] = swap;
   c++;
   }
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
