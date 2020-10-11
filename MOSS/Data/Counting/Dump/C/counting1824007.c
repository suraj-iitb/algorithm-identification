#include <stdio.h>

#define SIZE_OF_A 2000001
#define SIZE_OF_C 10001

int A[SIZE_OF_A],B[SIZE_OF_A];

int main(void){ 
   
  int i,k=0,j,n,C[SIZE_OF_C];
 
  scanf("%d",&n);
  for(j = 1 ; j <= n ; j++){
    scanf("%d",&A[j]);
  }
  for(j = 1 ; j <= n ; j++){
    if(A[j] > k){   
      k = A[j];
    }
  }
   
  for(i = 0 ; i <= k ; i++)  C[i] = 0;
  
  for(j = 1 ; j <= n ; j++) C[A[j]] = C[A[j]] + 1;
   
  for(i = 0 ; i <= k ; i++) C[i] = C[i] + C[i-1];
   
  for(j = n ; j >= 1 ; j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }

  for(j = 1 ; j <= n ; j++){
    if(j!=1) printf(" ");
    printf("%d",B[j]);
  }
  printf("\n");
   
  return 0;
}
