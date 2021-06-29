#include <stdio.h>
int main()
{
  int i,j,n,A[100],minj,count=0,temp,flag=1;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<n;i++)
    {
      minj=i;
      for(j=i;j<n;j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj=j;
	      flag=0;
	    }
	}
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      if(flag == 0)
	{
	  count++;
	  flag=1;
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
