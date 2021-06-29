#include"stdio.h"
#include"stdlib.h"
int main()
{
  int num;
  int *A;
  int i,j,k;
  int v;
  scanf("%d",&num);
  if(0<=num&&num<=1000)
    {
      A=(int*)malloc(sizeof(int)*num);
    }
  for(k=0;k<num;k++)
    {
      scanf("%d",&A[k]);
    }
  printf("%d",A[0]);
  for(k=1;k<num;k++)
    {
      printf(" %d",A[k]);
    }
  printf("\n");
  for(i=1;i<num;i++)
    {
      if(A[i-1]>A[i])
	{
	  v=A[i];
	  j=i-1;
	  while(j>=0&&A[j]>v)
	    {
	      A[j+1]=A[j];
	      j--;
	    }
	  A[j+1]=v;
	}
      printf("%d",A[0]);
      for(k=1;k<num;k++)
	{
	  printf(" %d",A[k]);
	}
      printf("\n");
    }
  return 0;
}

