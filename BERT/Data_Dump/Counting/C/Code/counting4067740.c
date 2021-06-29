#include <stdio.h>
#define AMAX 10000

int i,j;
int A[20000000],B[20000000],C[AMAX];

void CountingSort(int n)
{
  for(i=1;i<AMAX;i++)
  {
    C[i] = 0;
  }
  for(j=0;j<n;j++)
  {
    C[A[j+1]]++;
  }
  for(i=1;i<AMAX;i++)
  {
    C[i] = C[i] + C[i-1];
  }
  for(j=1;j<=n;j++)
  {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main()
{
  int n,data;
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
    scanf("%d",&A[i]);
  }
  CountingSort(n);
  for(i=1;i<=n;i++)
  {
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

