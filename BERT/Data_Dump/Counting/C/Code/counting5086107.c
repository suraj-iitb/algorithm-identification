#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define K 2000000


int main(){
  int n,i;
  int *A;
  int *B;
  int *C;
  A = malloc(sizeof(int)*K);
  B = malloc(sizeof(int)*K);
  C = malloc(sizeof(int)*N+1);
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  
  for(i=0;i<N+1;i++)
    C[i]=0;
  for(i=0;i<n;i++)
    C[A[i]] += 1;
  for(i=0;i<N+1;i++)
    C[i] += C[i-1];
  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }

  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i != n-1) printf(" ");
    else printf("\n");
  }
  free(A);
  free(B);
  free(C);
  return 0;
}

