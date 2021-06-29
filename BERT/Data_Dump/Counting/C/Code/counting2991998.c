#include<stdio.h>
int B[2000001], C[200001];
void CountingSort(int A[], int n)
{
  int i, j;
  for(i = 0; i <= 10001; i++)
    {
      C[i] = 0;
    }
  for(j = 1; j <= n; j++)
    {
      C[A[j]]++;
    }
  for(i = 1; i <= 10001; i++)
    {
      C[i] = C[i] + C[i-1];
    }
  for(j = n; j >= 1; j--)
  {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
}
  int main()
{
  int A[2000001], n, i;
  scanf("%d", &n);
  for(i = 1; i <= n; i++)
    {
      scanf("%d", &A[i]);
    }
      CountingSort(A, n);
  for(i = 1; i < n; i++)
    {
      printf("%d ", B[i]);
    }
  printf("%d\n", B[n]);
  return 0;
}

