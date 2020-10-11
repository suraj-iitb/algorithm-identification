#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int *A, *B;
  int C[VMAX+1];
  int n, i, j;

  

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  
  /* your code */
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    
  }
  
  for(i=0;i<VMAX;i++){
    C[i] = 0;
  }
  
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  for(i=1;i<VMAX;i++){
    C[i] = C[i] + C[i-1];
  }
  for(i=0;i<7;i++){
    // printf("%d ",C[i]);
  }
  // printf("\n");
  for(j=n-1;j>=0;j--){
    //printf("%d,",A[j]);
    B[C[A[j]]] = A[j];
    //printf("%d ",B[C[A[j]]]);
    C[A[j]]--;
  }
  // printf("\n");
  for(i=1;i<=n;i++){
    if(i !=n) printf("%d ",B[i]);
    else printf("%d",B[i]);
  }
  printf("\n");

  free(A);
  free(B);
  return 0;
}

