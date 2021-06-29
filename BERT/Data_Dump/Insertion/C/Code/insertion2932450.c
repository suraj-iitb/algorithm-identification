#include<stdio.h>
#define MAX 100
void printstate(int n,int A[]);
int main(void)
{
  int n;
  int i,j,key;
  int A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  printstate(n,A);
  for(i=1;i<n;i++)
    {
      key=A[i];
      j=i-1;
      while(j>=0&&A[j]>key)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=key;
      printstate(n,A);
    }
  return 0;
}
void printstate(int n,int A[])
{
  int i;
  for(i=0;i<n;i++)
    {
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
  printf("\n");
}

