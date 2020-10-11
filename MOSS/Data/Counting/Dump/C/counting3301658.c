#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define k 10000
short A[MAX];

int main( ){
  short B[MAX];
  int C[k];
  int n,i,j;

  scanf("%d",&n);
  for(i=0;i <= k;i++) C[i] = 0;

  for(j=1;j <= n;j++){
    scanf("%d",&A[j]);
    C[A[j]]++;
  }

  for(i=1;i <= k;i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j=n;j >= 1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i = 1; i<= n; i++){
    if( i > 1) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  return 0;
}

