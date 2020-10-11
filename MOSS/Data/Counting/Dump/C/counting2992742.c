#include"stdio.h"
#include"stdlib.h"
int *A;
int *B;
int *C;
int n;
void CountingSort(int k)
{
  int i,j;
  for(i=0;i<k;i++)
    {
      C[i]=0;
    }
  for(j=0;j<n;j++)
    {
      C[A[j]]++;
    }
  for(i=1;i<k;i++)
    {
      C[i]+=C[i-1];
    }
  for(j=n-1;j>=0;j--)
    {
      B[C[A[j]]-1]=A[j];
      C[A[j]]--;
    }
}
int main()
{
  int i,j;
  int k;
  scanf("%d",&n);
  A=(int*)malloc(sizeof(int)*n);
  B=(int*)malloc(sizeof(int)*n);
  scanf("%d",&A[0]);
  k = A[0];
  for(i=1;i<n;i++)
    {
      scanf("%d",&A[i]);
      if(k<A[i])k=A[i];
    }
  k++;
  C=(int*)malloc(sizeof(int)*(k));
  CountingSort(k);
  printf("%d",B[0]);
  for(i=1;i<n;i++)
    {
      printf(" %d",B[i]);
    }
  printf("\n");
}
