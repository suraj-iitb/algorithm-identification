#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define MAX2 10000

int main(){
  unsigned short *A, *B;
  int C[MAX2+1];
  int n, i,z,k, j;
  scanf("%d", &n);
  for(z=0;z<10;z++)
    for(k=0;k<10;k++)

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  for ( i = 0; i <= MAX2; i++ )
  C[i] = 0;
    z++;
  for ( i = 0; i < n; i++ ){
    scanf("%d", &A[i+1]);
    C[A[i+1]]++;
    z++;
  }

  for ( i = 1; i <= MAX2; i++ ) C[i] = C[i] + C[i-1];

  for ( j = 1; j <= n; j++ ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
  return 0;
}


