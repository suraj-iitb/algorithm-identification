#include <stdio.h>
#include <stdlib.h>

#define N 2000001
#define MAX 10000

int n;

void CountingSort( short *, short *);

int main()
{
  short *A, *B;
  int i;

  scanf("%d",&n);

  A = malloc( sizeof(short) * n+1);
  B = malloc( sizeof(short) * n+1);

  for( i = 1; i <= n; i++ )
    scanf("%hd",&A[i]);

  CountingSort( A, B );

  for( i = 1; i <= n; i++ )
    {
      if( i < n )
	printf("%hd ",B[i]);
      else
	printf("%hd\n",B[i]);
    }
  return 0;
}

void CountingSort( short *A, short *B )
{
  int i;
  int C[MAX+1];

  for( i = 0; i < MAX; i++ )
    C[i] = 0;

  for( i = 1; i <= n; i++ )
    C[A[i]]++;

  for( i = 1; i <= MAX; i++ )
    C[i] = C[i] + C[i-1];

  for( i = n; i >= 1; i-- )
    {
      B[C[A[i]]] = A[i];
      C[A[i]]--;
    }
}
  

