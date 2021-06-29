#include<stdio.h>
int main()
{
  int i,j,N,A[100],flag=1,n=0,x;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  
      while(flag)
	{
	  flag=0;
	  for(j=N-1;j>=1;j--)
	    {
	      if(A[j]<A[j-1])
		{
		  x=A[j];
		  A[j]=A[j-1];
		  A[j-1]=x;
		  flag=1;
		  n++;
		}
	    }
	
    }
  
  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n%d\n",A[N-1],n);

  return 0;
}
	  
