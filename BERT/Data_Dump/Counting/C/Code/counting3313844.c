#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void CountingSort(int[],int n);

int B[2000000];

int main()
{
  int n,i,A[2000000];

  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      scanf("%d",&A[i+1]);
    }
  CountingSort(A,n);
  for(i = 1;i <= n;i++)
    {
      if(i > 1) printf(" ");
      printf("%d",B[i]);
    }
  printf("\n");

  return 0;
}
void CountingSort(int A[],int n)
{
  int i,j,C[MAX];
  for(i = 0;i <= MAX;i++)
    {
      C[i] = 0;
    }
  for(j = 1;j <= n;j++)
    {
      C[A[j]]++;
    }
  for(i = 1;i <= MAX;i++)
    {
      C[i] = C[i] + C[i-1];
    }
  for(j = n;j >= 1;j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
}

