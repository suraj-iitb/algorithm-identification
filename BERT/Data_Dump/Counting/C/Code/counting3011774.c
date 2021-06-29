#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void Countsort(int ,int ,unsigned short *,unsigned short *);
void Countsort(int n,int k,unsigned short *A,unsigned short *B)
{
  int i,C[VMAX+1];

  for( i=0; i<=k; i++ )
    C[i] = 0;

  for( i=1; i<=n; i++ )
    C[A[i]]++;

  for( i=1; i<=k; i++ )
    C[i] = C[i] + C[i-1];

  for( i=n; i>=1; i-- )
    {
      B[C[A[i]]] = A[i];
      C[A[i]]--;
    }
  for( i=1; i<n; i++)
    printf("%d ",B[i]);
  printf("%d\n",B[n]); 
}
    
int main()
{
  unsigned short *A, *B;
  int k=0,n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for( i=0; i<n; i++ )
    {
      scanf("%hd",&A[i+1]);
      if( k < A[i] ) k = A[i];
    }
  Countsort(n,k,A,B);

  return 0;
}

