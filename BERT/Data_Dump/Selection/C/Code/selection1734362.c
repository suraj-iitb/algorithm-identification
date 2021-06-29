#include<stdio.h>
int main()
{
  int i,A[100],n,minj,j,count=0,B;

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
	  if(A[j]<A[minj])
	    {
	      minj=j;
	    }
	}
      if(minj>i)
	{
	  B=A[i];
	  A[i]=A[minj];
	  A[minj]=B;
	  count++;
     
	}
    }

  for(i=0;i<n-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n%d\n",A[n-1],count);

  return 0;
}
