#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define VMAX 10000

void CountingSort( short *, short *, int );

int n;

int main()
{
  unsigned short *A, *B;
  int i, j, k=0;

  scanf("%d", &n);

  A = malloc( 1 + n * sizeof(short));
  B = malloc( 1 + n * sizeof(short));

  for(  i=1; i<=n; i++ )
    {
      scanf("%hd", &A[i]);
      if( k < A[i] ) k = A[i];
    }

  CountingSort( A, B, k );

  for( i=1; i<n; i++ ) printf("%d ", B[i]);
  printf("%d\n", B[n]);

  return 0;
}


void CountingSort( short *A, short *B, int k )
{
  int i, j, C[k+1];

  for( i=0; i<=k; i++ )
    C[i] = 0;

  for( j=1; j<=n; j++ )
    C[A[j]]++;

  for( i=1; i<=k; i++ )
    C[i] = C[i] + C[i-1];

  for( j=n; j>0; j-- )
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
}

