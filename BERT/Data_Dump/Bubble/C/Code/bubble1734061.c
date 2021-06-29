#include<stdio.h>

int main()
{
  int n,i,j,t,A[100],flag=1,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  i=0;
  while(flag)
    {
      flag=0;
      for(j=n-1;j>=i+1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      t=A[j];
	      A[j]=A[j-1];
	      A[j-1]=t;
	      flag=1;
	      count++;
	    }
	}
      i++;
    }
  
  for(i=0;i<n-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}
