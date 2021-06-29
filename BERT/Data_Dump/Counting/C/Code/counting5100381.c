#include<stdio.h>
#include<stdlib.h>

#define N_LIMIT 2000001
#define VN_LIMIT 10000

int main(){
  unsigned short *A, *B;
  int cntarr[VN_LIMIT+1],i,j,n;

  scanf("%d", &n);

  A = malloc(sizeof(short) * n + 1);
  B = malloc(sizeof(short) * n + 1);

  for ( i = 0; i <= VN_LIMIT; i++ ){
      cntarr[i] = 0;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%hu", &A[i + 1]);
    cntarr[A[i + 1]]++;
  }

  for ( i = 1; i < VN_LIMIT + 1; i++ ) cntarr[i] = cntarr[i -1] + cntarr[i];

  for ( j = 1; j < n + 1; j++ ){
    B[cntarr[A[j]]] = A[j];
    cntarr[A[j]]--;
  }

  for ( i = 1; i < n + 1; i++ ) {
    if ( 1 < i ) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  return 0;
}
