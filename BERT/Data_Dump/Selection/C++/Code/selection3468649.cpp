#include <stdio.h>

int main()
{
  int N, A[100], count;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);

  for (int i = 0; i < N; i++)
  {
    int minj = i;
    for (int j = i + 1; j < N; j++)
    {
      if (A[j] < A[minj])
      {
        minj = j;
      }
    }
    if (minj > i)
    {
      int tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      count++;
    }
  }

  for (int i = 0; i < N; i++)
  {
    if (i > 0)
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);
}

