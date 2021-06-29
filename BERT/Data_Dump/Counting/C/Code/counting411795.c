#include <stdio.h>
int A[2000001],B[2000001];
int main(void){ 
  
  int i,k=0,j,n,C[10001];

  scanf("%d",&n);
  for(j = 1 ; j <= n ; j++){
    scanf("%d",&A[j]);
  }
  for(j = 1 ; j <= n ; j++){
    if(A[j] > k){   
      k = A[j];
    }
  }
  
  for(i = 0 ; i <= k ; i++){
    C[i] = 0;
  }
  for(j = 1 ; j <= n ; j++){
    C[A[j]] = C[A[j]] + 1;
  }
  
  for(i = 0 ; i <= k ; i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j = n ; j >= 1 ; j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
  for(j = 1 ; j <= n ; j++){
    printf("%d",B[j]);
    if(j <= n-1){
      printf(" ");
    }
  }
  printf("\n");
  
  return 0;
}
