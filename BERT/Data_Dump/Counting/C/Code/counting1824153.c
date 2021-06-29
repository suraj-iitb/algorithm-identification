#include <stdio.h>
#include <stdlib.h>

#define N 10000

int n;

void Countingsort(unsigned short* ,unsigned short*,int);

int main(){

  unsigned short *A, *B;

  int k=0;
  int i;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
      if(k<A[i+1]) k = A[i+1];
  }


  Countingsort(A,B,k);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n) printf(" ");
  }

  printf("\n");

  return 0;

}

void Countingsort(unsigned short *A, unsigned short *B, int k){

  int i,C[k];

  for ( i = 0; i <= k; i++ ) C[i] = 0;

  for ( i = 1; i <= n; i++ )  C[A[i]]++;

  for ( i = 1; i <= k; i++ ) C[i] = C[i] + C[i - 1];

  for ( i = n; i > 0; i-- ){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

}
