#include<stdio.h>

int main(void)
{
  int c = 0, i, j, minj, N, t;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++)
  {
    scanf("%d",&A[i]);
  }
  for(i = 0; i < N; i++)
  {
    minj = i;
    for(j = i; j < N; j++)
    {
      if(A[j] < A[minj])
        {
          minj = j;
        }
    }
      if(minj > i)
      {
        t = A[i];
        A[i] = A[minj];
        A[minj] = t;
        c++;
      }
    }
    for(i = 0; i < N - 1; i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n%d\n",A[N - 1], c);
  return 0;
}
