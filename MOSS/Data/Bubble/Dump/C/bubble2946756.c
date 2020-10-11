#include<stdio.h>
#define N 100
void printStatus(int,int[]);
int main(void)
{
  int A[N];//array
  int i,j;//counter
  int tmp;//temporary variable to swap 2 elements
  int count=0;//count how many times sort is done
  int n;//the number of elements
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  for(i=0;i<n;i++)
    {
      for(j=n-1;j>i;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      tmp=A[j];
	      A[j]=A[j-1];
	      A[j-1]=tmp;
	      count++;
	    }
	}
    }
  printStatus(n,A);
  printf("%d\n",count);
  return 0;
}
void printStatus(int n,int A[])
{
  int i;
  for(i=0;i<n;i++)
    {
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
  printf("\n");
}

