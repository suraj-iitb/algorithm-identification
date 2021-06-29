#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define M 2000000

int main()
{
  unsigned short *A,*B;
  int i,j,n,C[N+1];

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=1;i<n+1;i++) scanf("%d",&A[i]);

  for(i=0;i<N;i++) C[i] = 0;

  for(j=1;j<n+1;j++) C[A[j]]++;

  for(i=1;i<N;i++) C[i] = C[i]+C[i-1];

  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[n]);

  return 0;
}

