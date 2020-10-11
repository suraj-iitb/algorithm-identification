#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000
#define E_MAX 10000

main(){
  int n, i;
  int *A, *B;
  int C[E_MAX+1];
  
  scanf("%d", &n);
  
  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  
  for( i = 0; i <= E_MAX; i++) C[i] = 0;
  
  for( i = 0; i < n; i++){
    scanf("%d", &A[i+1]);
    C[A[i+1]]++;
  }
  
  for( i = 1; i <= E_MAX; i++) C[i] = C[i] + C[i-1];
  
  for( i = n+1; 0 < i; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  
  for( i = 1; i <= n; i++){
    if( i == n ) printf("%d\n", B[i]);
    else printf("%d ", B[i]);
  }

  return 0;
  
}
