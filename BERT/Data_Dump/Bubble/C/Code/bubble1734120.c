#include <stdio.h>
int main()
{
  int i,flag=1,n,A[100],temp,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  while(flag)
    {
      flag=0;
      for(i=n-1;i>0;i--)
	{
	  if(A[i] < A[i-1])
	    {
	      temp=A[i];
	      A[i]=A[i-1];
	      A[i-1]=temp;
	      count++;
	      flag=1;
	    }
	}
    }
    

  for(i=0;i<n;i++)
    {
      if(i == n-1)
	{
	  printf("%d\n%d\n",A[i],count);
	}
      else
	{
	  printf("%d ",A[i]);
	}
    }

  return 0;
}
