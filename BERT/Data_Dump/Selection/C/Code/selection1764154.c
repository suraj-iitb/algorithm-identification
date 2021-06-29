#include <stdio.h>
#define N 100
int main()
{
  int i,j,minj,count=0,n,kk;
  int A[N];

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
      kk=A[i];
      A[i]=A[minj];
      A[minj]=kk;
      if(i!=minj) count=count+1;
    }


  for(i=0;i<n-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d",A[i]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}
