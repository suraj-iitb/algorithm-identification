#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000
int n;

void CountingSort(int A[], int B[], int k)
{
  int C[k + 1];

  for (int i = 0; i <= k; i++)
  {
    C[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    C[A[i]]++;
  }
  for (int i = 1; i <= k; i++)
  {
    C[i] = C[i] + C[i - 1];
  }

  int j = n;
  for (int i = 0; i < n; i++)
  {
    j = n - 1 - i;
    B[C[A[j]] - 1] = A[j];
    C[A[j]]--;
  }
}

int main()
{
  int *A;
  int *B;
  A = (int *)malloc(MAX * sizeof(int));
  B = (int *)malloc(MAX * sizeof(int));

  scanf("%d\n", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  CountingSort(A, B, 10000);

  for (int i = 0; i < n; i++)
  {
    printf("%d", B[i]);
    if (i < n - 1)
    {
      printf(" ");
    }
    else
    {
      printf("\n");
    }
  }
  return 0;
}
