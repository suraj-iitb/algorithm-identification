#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  for (i=0; i<=VMAX; i++) C[i] = 0;

  /* C[i] に i の出現数を記録する */
  for (j=1; j<=n; j++){
    scanf("%d",&A[j]);
    C[A[j]]++;
  }
  /* C[i] に i 以下の数の出現数を記録する*/
  for (i=1; i<=VMAX; i++) C[i] = C[i] + C[i-1];

  for (j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(j=1; j<n; j++) printf("%d ",B[j]);
  printf("%d\n",B[j]);
  return 0;
}
