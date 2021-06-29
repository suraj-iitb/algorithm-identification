#include <stdio.h>

int main()
{
  int A[100], N, i, temp, cnt=0, x=0, flag = 1;

  scanf("%d", &N);
  for(i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  while(flag)
  {
    flag = 0;
    for(i = N-1; i >= 1+x; i--)
    {
      if(A[i] < A[i-1])
      {
        temp = A[i];
        A[i] = A[i-1];
        A[i-1] = temp;
        cnt++;
        flag = 1;
      }
    }
    x++;
  }

  for(i = 0; i < N-1; i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[i], cnt);

  return 0;
}

