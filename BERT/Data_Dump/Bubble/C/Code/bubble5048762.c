#include<stdio.h>
#include<stdlib.h>

int main()
{
  int N,i,j,k,flag,count=0;
  int *A;

  scanf("%d",&N);
  A=(int *)malloc(sizeof(int)*N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }

  flag=1;
  while(flag)
    {
      flag=0;
      for(j=N-1;j>0;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      k=A[j];
	      A[j]=A[j-1];
	      A[j-1]=k;
	      flag=1;
	      count++;
	    }
	  
	    
	}
    }

  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  




  return 0;
}

