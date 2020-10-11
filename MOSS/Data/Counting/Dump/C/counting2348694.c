#include <stdio.h>
#include <stdlib.h>

#define NMAX 2000000
#define AMAX 10000

int main(){

  int i, n;
  int C[AMAX+1];
  int *A, *B;
  
  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for(i=0; i<= AMAX; i++) C[i] = 0;

  for(i=0; i<n; i++){
    scanf("%d", &A[i+1]);
    C[A[i+1]]++;
  }

  for(i=1; i<=AMAX; i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(i=1; i<=n; i++){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i=1; i<=n; i++){
    printf("%d", B[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");
  
  return 0;
}
