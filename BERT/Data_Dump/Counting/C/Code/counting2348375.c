#include<stdio.h>
#include<stdlib.h>

#define K 10000

int main(){
  int i,j,n,C[K+1];
  int *A,*B;

  scanf("%d",&n);

  A = (int *)malloc(sizeof(int) * n+1);
  B = (int *)malloc(sizeof(int) * n+1);
  
  for(i = 0 ; i < n ; i++)
    scanf("%d",&A[i+1]);

  for(i = 0 ; i <= K ; i++)
    C[i] = 0;

  for(j = 1 ; j <= n ; j++)
    C[A[j]]++;

  for(i = 1 ; i <= K ; i++)
    C[i] = C[i] + C[i-1];

  for(j = 1 ; j <= n ; j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }


  for(i = 1 ; i <= n ; i++){
    printf("%d",B[i]);

    if(i < n) printf(" ");
  }

  printf("\n");


  return 0;
}
  
