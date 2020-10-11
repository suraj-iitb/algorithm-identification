#include <stdio.h>

int main(void)
{
  int N, i, j, t, flag, c = 0;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }
  for(i = 0; i < N; i++)
  {
    flag = 1;
    while(flag)
    {
      flag = 0;
      for(j = N - 1; j > 0; j--)
      {
        if(A[j] < A[j - 1])
        {
          t = A[j];
          A[j] = A[j-1];
          A[j-1] = t;
          flag = 1;
          c++;
          break;
        }
      }
    }
  }
  for(i = 0; i < N - 1; i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[N - 1], c);
  return 0;
}
