#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int *A, *B, C[VMAX];
  int n;
  int i,j,k = 0;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for( i = 0;i < n;i++){
    scanf("%d",&A[i]);
    if(A[i] > k){
      k = A[i];
    }
  }

  for(i = 0;i <= k;i++){
    C[i] = 0;
  }
     
  for( j = 0;j < n;j++){
    C[A[j]]++;
  }
  
  for( i = 1;i <= k;i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j = n - 1;j >= 0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1;i <= n;i++){
    if(i == n ){
      printf("%d",B[i]);
    }
    else printf("%d ",B[i]);
  }
  printf("\n");

  return 0;
}

