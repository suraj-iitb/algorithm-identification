#include<stdio.h>
#define N 100
void printStatus(int,int[]);
int main(void)
{
  int A[100];//array
  int i,j;//counter
  int n;//the number of elements
  int mini;//indication of min. element
  int tmp;//temporary valuable for swapping
  int count=0;//counter of swap operations
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  for(i=0;i<n;i++)
    {
      mini=i;
      for(j=i;j<n;j++)
	{
	  if(A[j]<A[mini]) mini=j;
	}
      if(i!=mini)
	{
          tmp=A[i];
          A[i]=A[mini];
          A[mini]=tmp;
          count++;
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

