#include <stdio.h>

int main()
{
  int i,v,j,n,k;
  scanf("%d",&n);

  int A[100];
  for(k=0;k<n;k++)
    {
      scanf("%d",&A[k]);
    }
  
  for(k=0;k<n-1;k++)
    {
      printf("%d ",A[k]);
    }
  printf("%d\n",A[n-1]);
  
  for(i=1;i<n;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0&&A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=v;

      for(k=0;k<n-1;k++)
	{
	  printf("%d ",A[k]);
	}
      printf("%d\n",A[n-1]);
    }
  
  return 0;
}

