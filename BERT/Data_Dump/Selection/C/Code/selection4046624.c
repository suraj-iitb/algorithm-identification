#include <stdio.h>

int main()
{
  int i,j,n,k,o,minj,count=0;
  scanf("%d",&n);
  int A[100];
  for(k=0;k<n;k++)
    {
      scanf("%d",&A[k]);
    }

  for(i=0;i<=n-1;i++)
    {
      minj=i;
      for(j=i;j<=n-1;j++)
	{
          if(A[j]<A[minj])
	    {
	      minj=j;
	    }
	}
      if(i!=minj)
	{
	  count++;
	  o=A[i];
	  A[i]=A[minj];
	  A[minj]=o;
	}
    }

  for(k=0;k<n-1;k++)
    {
      printf("%d ",A[k]);
    }
  printf("%d\n",A[n-1]);
  
  printf("%d\n",count);
  return 0;
}
	  

