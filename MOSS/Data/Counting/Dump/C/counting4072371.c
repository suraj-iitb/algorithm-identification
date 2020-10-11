#include <stdio.h>
#define MAX 2000001
#define VMAX 10000
void CountingSort(void);

int A[MAX],B[MAX],n;
int main()
{
  int i;
  scanf("%d",&n);
  for(i=1;i<n+1;i++)
    {
      scanf("%d",&A[i]);
    }
  CountingSort();
  for(i=1;i<n;i++)
    {
      printf("%d ",B[i]);
    }
  printf("%d\n",B[n]);
  return 0;
}

void CountingSort(void)
{
  int i,j,C[VMAX+1];
  for(i=0;i<=VMAX;i++)
    {
      C[i]=0;
    }
  for(j=1;j<n+1;j++)
    {
      C[A[j]]=C[A[j]]+1;
    }
   
  for(i=1;i<=VMAX;i++)
    {
      C[i]=C[i]+C[i-1];
     
    }
 
  
  for(j=n;j>=1;j--)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]=C[A[j]]-1;
    }
}

