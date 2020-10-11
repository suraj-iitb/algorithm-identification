#include <stdio.h>
#include <stdlib.h>
#define V 10000

int main(){
  int i, j, n, *A, *B, C[V+1];
  scanf("%d", &n);
  
  A=(int *)malloc(sizeof(int)*n+1);
  B=(int *)malloc(sizeof(int)*n+1);
  

  for(i=0; i<=V; i++){
    C[i]=0;
  }
  
  for(j=1; j<=n; j++){
    scanf("%d", &A[j]);
    C[A[j]]++;
  }
  
  for(i=1; i<=V; i++){
    C[i]=C[i]+C[i-1];
  }
  
  for(j=n; j>=1; j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  
  
  for(i=1; i<=n; i++){
    if(i>1) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
  
  free(A);
  return 0;
}
