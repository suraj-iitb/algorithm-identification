#include <stdio.h>
#include <stdlib.h>
#define N 2000000
#define Ai 10000

int main(){
  int *A,*B,C[Ai+1];
  int n,i,j;

  scanf("%d",&n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  for(i=0;i<=Ai;i++)
    C[i]=0;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    C[A[i]]++;
  }

  for(i=1;i<=Ai;i++)
    C[i]=C[i]+C[i-1];


  for(j=0;j<n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);


  return 0;
}
