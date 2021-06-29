#include <stdio.h>

int bubbleSort(int A[], int N)
{
  int flag = 1;
  int c = 0;
  for (size_t j = 0; flag; j++)
  {
    flag = 0;
    for (size_t i = N - 1; i >= j + 1; i--)
    {
      int tmp = A[i];
      if (A[i - 1] > A[i])
      {
        A[i] = A[i - 1];
        A[i - 1] = tmp;
        flag = 1;
        c++;
      }
    }
  }
  return c;
}

void printArray(int A[], int N)
{
  for (size_t i = 0; i < N; i++)
  {
    printf("%d", A[i]);
    if (i == N - 1)
      printf("%s", "\n");
    else
      printf("%s", " ");
  }
}

int main()
{
  int N, R[100];
  scanf("%d", &N);
  for (size_t i = 0; i < N; i++)
    scanf("%d", &R[i]);

  int c = bubbleSort(R, N);
  printArray(R, N);
  printf("%d\n", c);
  return 0;
}

