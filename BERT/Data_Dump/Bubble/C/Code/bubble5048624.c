#include <stdio.h>

#define MN 100

int main()
{
  int A[MN], max, i, j, count, tmp;

  scanf("%d", &max);

  for (i = 0; i < max; i++)
  {
    scanf("%d", &A[i]);
  }

  for (i = 0; i < max - 1; i++)
  {
    for (j = max - 1; j > 0 && j > i; j--)
    {
      if (A[j] < A[j - 1])
      {
        count++;
        tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
      }
    }
  }

  for (i = 0; i < max; i++)
  {
    if (i == max - 1)
    {
      printf("%d", A[i]);
    }
    else
    {
      printf("%d ", A[i]);
    }
  }
  printf("\n%d\n", count);
  return 0;
}
