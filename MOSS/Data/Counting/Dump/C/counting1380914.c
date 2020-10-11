#include<stdio.h>
 
int A[20000000], B[20000000], C[20000000], n;

int main(void)
{
 
  int i;
  int vmax = 0;
 
  scanf("%d",&n);
 
  for(i = 1;i <= n;i++)
    {
      scanf("%d", &A[i]);
      if(vmax < A[i])
    {
      vmax = A[i];
    }
    }
 
  CountingSort(vmax);
 
  for(i = 1;i <= n;i++)
    {
      if(i > 1) printf(" ");
      printf("%d",B[i]);
    }
  printf("\n");
  return 0;
}

void CountingSort(int k)
{
  int i, j;
  for(i = 0; i <= k; i++)
    {
      C[i] = 0;
    }
  for(j = 1;j <= n;j++)
    {
      C[A[j]]++;
    }
  for(i = 1;i <= k;i++)
    {
      C[i] = C[i] + C[i - 1];
    }
  for(j = n;j > 0;j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
}
