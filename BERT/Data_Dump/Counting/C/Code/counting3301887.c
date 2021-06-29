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

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  for(i=0;i<VMAX+1;i++)
    C[i] = 0;

  for(j=0;j<n;j++)
    C[A[j]]++;

  for(i=1;i<VMAX+1;i++)
    C[i] = C[i] + C[i-1];

  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",B[i+1]);
  }

  printf("\n");

  return 0;
}

