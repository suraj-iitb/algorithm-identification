#include <stdio.h>

int main()
{
  int N;
  int A[1000];
  int i, j, v;

  scanf("%d", &N);
  for (i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  for (i = 1; i <= N; i++)
  {
    for (j = 0; j < N - 1; j++)
    {
      printf("%d ", A[j]);
    }
    printf("%d", A[N - 1]);
    printf("\n");
    if (i == N)
    {
      break;
    }

    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v)
    {
      A[j + 1] = A[j];
      j--;
      A[j + 1] = v;
    }
  }

  return 0;
}
