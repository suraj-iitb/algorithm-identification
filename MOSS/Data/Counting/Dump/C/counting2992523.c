#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main () {

  int C[VMAX + 1];
  int n,i,j;
  scanf("%d",&n);
  int A[n+1], B[n+1];

  for (i=0;i<=VMAX;i++) C[i] = 0;
  for (i=0;i<n;i++) {
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

  for (i=1;i<=VMAX;i++) C[i] = C[i] + C[i-1];

  for (j=1;j<=n;j++) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
  for (j=1;j<=n;j++) {
    if (j > 1) printf(" ");
    printf("%d",B[j]);
  }
  printf("\n");
}

