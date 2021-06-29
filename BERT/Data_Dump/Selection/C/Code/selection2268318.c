#include <stdio.h>

int main()
{
  int i,j,n,s,count=0,k=0,A[100];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<=n-1;i++)
    {
      s = i;
      for(j=i;j<=n-1;j++)
	{
	  if(A[j] < A[s])
	    {
	      s = j;
	    }
	}
      if(A[i] != A[s])
	{
	  k = A[i];
	  A[i] = A[s];
	  A[s] = k;
	  count++;
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
  
