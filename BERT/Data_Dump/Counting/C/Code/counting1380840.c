#include <stdio.h>
#define N 20000000
 
int A[N], B[N], C[N], n;

 
     
 int main()
{
 
  int i;
  int max=0;
 
  scanf("%d",&n);
 
  for(i = 1;i <= n;i++)
    {
      scanf("%d", &B[i]);
      if(max< B[i])
    {
      max = B[i];
    }
    }
 
  CountingSort(max);
 
  for(i = 1;i <= n;i++)
    {
      if(i > 1) printf(" ");
      printf("%d",C[i]);
    }
  printf("\n");
  return 0;
}
 void CountingSort(int k)
{
  int i, j;
  for(i = 0; i <= k; i++)
    {
      A[i] = 0;
    }
  for(j = 1;j <= n;j++)
    {
      A[B[j]]++;
    }
  for(i = 1;i <= k;i++)
    {
      A[i] = A[i] + A[i - 1];
    }
  for(j = n;j > 0;j--)
    {
      C[A[B[j]]] = B[j];
      A[B[j]]--;
    }
}
