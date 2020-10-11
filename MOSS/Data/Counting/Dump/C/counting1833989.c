#include <stdio.h>
#include <stdlib.h>
#define MAX_A 2000001 
#define MAX_C 10000  

int n;
int *A;
int *B;
int C[MAX_C];

void CountingSort()
{
  int i;

  for(i = 0; i < MAX_C; i++)
    {
      C[i] = 0;
    }
  for(i = 1; i <= n; i++)
    {
      C[A[i]]++;
    }
  for(i = 1; i < MAX_C; i++)
    {
      C[i] += C[i - 1];
    }
  for(i = n; i > 0; i--)
    {
      B[C[A[i]]] = A[i];
      C[A[i]]--;
    }
}

int main()
{
  int i;

  scanf("%d", &n);

  A = (int *)malloc((n + 1) * sizeof(int));
  B = (int *)malloc((n + 1) * sizeof(int));

  for(i = 1; i <= n; i++)
    {
      scanf("%d", &A[i]);
    }

  CountingSort();

  for(i = 1; i < n; i++)
    {
      printf("%d ", B[i]);
    }
  printf("%d\n", B[n]);

  return 0;
}
