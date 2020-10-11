#include<stdio.h>

#define N 2000000
#define K 10000

void countingSort(int *, int *, int);

int A[N+1], B[N+1];

int main()
{
  int i, n;

  scanf("%d", &n);
  for(i=1; i<=n; i++)
    {
      scanf("%d", &A[i]);
    }

  countingSort(A, B, n);

  for(i=1; i<=n; i++)
    {
      printf("%d", B[i]);
      if(i+1<=n) printf(" ");
    }
  printf("\n");
  
  return 0;
}

void countingSort(int *A, int *B, int n)
{
  int i, j;
  int C[K+1];

  for(i=0; i<=K; i++) C[i] = 0;

  for(j=1; j<=n; j++) C[A[j]]++;

  for(i=1; i<=K; i++) C[i] = C[i]+C[i-1];

  for(j=n; j>=1; j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
}
