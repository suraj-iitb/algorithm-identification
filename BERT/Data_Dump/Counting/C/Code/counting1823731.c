#include <stdio.h>
#include <stdlib.h>

#define VMAX 100000


int main(){

  int i,j,n,C[VMAX+1];

  scanf("%d",&n);
  
  short *A,*B;

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);


  for(i=1;i<n+1;i++)scanf("%d",&A[i]);
  
  for(i=0;i<=VMAX;i++)C[i]=0;
  
  for(j=1;j<=n;j++)C[A[j]]++;

  for(i=1;i<=VMAX;i++) C[i] = C[i] + C[i-1];

  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  
  for(i=1;i<n;i++)printf("%d ",B[i]);
  printf("%d\n",B[n]);
  return 0;
}
