#include <stdio.h>
void pr(int A[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
void insertionSort(int A[],int n)
{
  int i,j,v;
  for(i=1;i<n;i++)
  {
    v = A[i];
    j = i-1;
    while(j>=0&&A[j]>v)
    {
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    pr(A,n);
  }
}
int main()
{
  int n,A[100],i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&A[i]);
  }
  pr(A,n);
  insertionSort(A,n);
  return 0;
}

