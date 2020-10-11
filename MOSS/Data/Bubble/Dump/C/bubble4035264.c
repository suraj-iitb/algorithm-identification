#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N,i,j,v,count=0,flag;
  int *A;

  scanf("%d",&N);
  if(N<1 || N>100) exit(2);
  A=(int *)malloc(sizeof(int)*N);

  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(A[i]<0 || A[i]>100) exit(1);
    }

  flag=1;
  while(flag)
    {
      flag=0;
      for(j=N-1;j>=1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      v=A[j];
	      A[j]=A[j-1];
	      A[j-1]=v;
	      flag=1;
	      count++;
	    }
	}
    }

  for(i=0;i<N-1;i++)
	{
	  printf("%d ",A[i]);
	  
	}
  printf("%d",A[N-1]);
  printf("\n");

  printf("%d\n",count);


  return 0;
}

