#include <stdio.h>

int main()
{
  int A[100], N, i, j, minj, temp, cnt;

  scanf("%d", &N);
  for(i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  for(i = 0; i < N-1; i++)
  {
    minj = i;

    for(j = i; j < N; j++)
    {
      if(A[minj] > A[j])
      {
        minj = j;
      }
    }

    if(minj != i)
    {
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      cnt++;
    }
  }

  for(i = 0; i < N-1; i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[i], cnt);

  return 0;
}

