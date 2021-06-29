#include <stdio.h>
#include <stdlib.h>
#define MAX 2000005
#define VMAX 10010

int main(){
  int *A, *B;
  int C[VMAX+1]={};
  int n, i, j;
  int max=0;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  /* your code */

  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
    C[A[i]] += 1;
    if(max<=A[i]) max = A[i];
  }

  for(i=1;i<max+1;i++) {
    C[i] += C[i-1];
  }

  for(i=n-1;i>=0;i--) {
    B[(C[A[i]]) - 1] = A[i];
    C[A[i]] -= 1;
  }

  /*
  for(i=0;i<max+1;i++) {
    printf("%d ",C[i]);
  }
  printf("\n");
  */
  
  for(i=0;i<n-1;i++) {
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n-1]);

  return 0;
}

