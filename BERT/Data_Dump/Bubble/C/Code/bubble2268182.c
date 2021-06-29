#include <stdio.h>

int main()
{
  int i,j,n,count=0,k=0;
  int A[100];

  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<=n-1;i++)
    {
      for(j=n-1;j>=i+1;j--)
	{
	  if(A[j] < A[j-1])
	    {
	      k = A[j];
	      A[j] = A[j-1];
	      A[j-1] = k;
	      count++;
	    }
	}
    }
  for(i=0;i<n-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);

  return 0;
}
