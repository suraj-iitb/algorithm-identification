#include <stdio.h>
#include <stdlib.h>

#define N 10000

int main()
{
  int i, j, n;
  int *A, *B;
  int C[N+1];
  
  scanf("%d",&n);

  A = (int *)malloc(sizeof(int)*n+1);
  B = (int *)malloc(sizeof(int)*n+1);
  
  for( i=1 ; i<=n ; i++ )
    scanf("%d",&A[i]);

  for( i=1 ; i<N ; i++ )
    C[i] = 0;

  for( j=1 ; j<=n ; j++ )
    C[A[j]]++;

  for( i=1 ; i<=N ; i++ )
    C[i] = C[i]+C[i-1];

  for( j=n ; j>=1 ; j-- ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for( i=1 ; i<=n-1 ; i++ )
    printf("%d ",B[i]);
  printf("%d\n",B[i]);

  free(A);
  free(B);
    
  return 0;
}
