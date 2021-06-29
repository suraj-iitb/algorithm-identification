#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int *A, *B;
  int C[VMAX+1];
  int n,i,j;

  scanf("%d",&n);
  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for(j=1;j<=n;j++) scanf("%d",&A[j]);
  for(i=0;i<VMAX;i++) C[i] = 0;
  for(j=1;j<=n;j++) C[A[j]]++;
  for(i=1;i<VMAX;i++) C[i]=C[i]+C[i-1];
  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}
