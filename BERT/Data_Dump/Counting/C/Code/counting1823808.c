#include <stdio.h>
#include <stdlib.h>
#define VMAX 10000
int n;

void CountingSort(int *A, int *B){
  int i,j;
  int C[VMAX+1];
  
  // init
  for(i=0; i<=VMAX; i++) C[i] = 0;

  // count
  for(j=0; j<n; j++) C[A[j+1]]++;

  // accum
  for(i=1; i<=VMAX; i++) C[i] = C[i] + C[i-1];

  // restruct
  for(j=1; j<=n; j++) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

}

int main(){
  int *A,*B;
  int i;

  // input and alloc
  scanf("%d",&n);
  A = (int *)malloc(sizeof(int) * n+1);
  for(i=0; i<=n; i++) A[i] = 0;
  B = (int *)malloc(sizeof(int) * n+1);
  for(i=0; i<=n; i++) B[i] = 0;
  for(i=0; i<n; i++) scanf((i == n-1) ? "%d" : "%d ",&A[i+1]);

  // sort
  CountingSort(A,B);

  // output
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  free(A);
  free(B);

  return 0;
}
