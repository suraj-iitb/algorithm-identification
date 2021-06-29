#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, minj, mNum, tmp, jPos, count=0;
  int *A;

  scanf("%d", &mNum);
  if (mNum <= 100)
  {
    A = (int *)malloc(sizeof(int) * mNum);
  }

  for (i = 0; i < mNum; i++)
  {
    scanf("%d", &A[i]);
  }

  for (i = 0; i < mNum - 1; i++)
  {
    minj = A[i];
    for (j = i + 1; j < mNum; j++)
    {
      if (minj > A[j])
      {
        minj = A[j];
        jPos = j;
      }
    }
    if (minj != A[i])
    {
      count++;
      tmp = A[i];
      A[i] = minj;
      A[jPos] = tmp;
    }
  }

  for (i = 0; i < mNum; i++)
  {
    if (i != mNum - 1)
    {
      printf("%d ", A[i]);
    }
    else
    {
      printf("%d", A[i]);
    }
  }
  printf("\n%d\n", count);

  return 0;
}
