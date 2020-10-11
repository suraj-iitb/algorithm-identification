#include <stdio.h>
#include <stdlib.h>

#define VMAX 10000

void CountingSort(unsigned short *, unsigned short *, int);

int main(){
  unsigned short *A, *B;
  int n, i;

  scanf("%d",&n);

  A = malloc(sizeof(short)*(n+1));
  B = malloc(sizeof(short)*(n+1));

  /* your code */
  for(i = 1; i <= n; i++) {
    scanf("%hu",&A[i]);
  }
  
  CountingSort(A, B, n);

  for(i = 1; i <= n; i++) {
    if(i != 1) printf(" ");
    printf("%u",B[i]);
  }
  printf("\n");


  free(A);
  free(B);
  return 0;
}

void CountingSort(unsigned short *A, unsigned short *B, int n)
{
  int C[VMAX+1];
  int i;

  for(i = 0; i <= VMAX; i++) {
    C[i] = 0;
  }

  for(i = 1; i <= n; i++) {
    C[A[i]]++;
  }

  for(i = 1; i <= VMAX; i++) {
    C[i] = C[i] + C[i-1];
  }

  for(i = n; i >= 1; i--) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

