#include <stdio.h>
#include <stdlib.h>


#define M 10000

int main(){

  int *A, *B;
  int n, i, j;
  int count[M + 1];

  scanf("%d", &n);
  
  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for(i=0;i<=M;i++)
    count[i] = 0;

  for(i=0;i<n;i++){
    scanf("%d", &A[i+1]);

    count[A[i+1]]++;
  }

  for(i=1;i<=M;i++)
    count[i] = count[i] + count[i-1];
  
  for(j=1;j<=n;j++){
    B[count[A[j]]] = A[j];
    count[A[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d", B[i]);
  }

  printf("\n");

  return 0;
}

