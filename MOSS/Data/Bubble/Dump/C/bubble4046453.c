#include <stdio.h>

int main()
{
  int i=0,j,n,k,o,flag=1,count=0;
  scanf("%d",&n);
  int A[100];
  for(k=0;k<n;k++)
    {
      scanf("%d",&A[k]);
    }
  while(flag==1)
    {
      flag=0;
      for(j=n-1;j>=i+1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      o=A[j];
	      A[j]=A[j-1];
	      A[j-1]=o;
	      flag = 1;
	      count++;
	    }
	}
      i++;
    }
  for(k=0;k<n-1;k++)
    {
      printf("%d ",A[k]);
    }
  printf("%d\n",A[n-1]);
  
  printf("%d\n",count);
  return 0;
}
	  
	
  

