#include <stdio.h>
#define N 100
int main()
{
  int A[N],flag=1,n,i,count=0,c;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  while(flag)
    {
      flag=0;
      for(i=n-1;i>=1;i--)
	{	  
	  if(A[i]<A[i-1])
	    {
	      c=A[i];
	      A[i]=A[i-1];
	      A[i-1]=c;
	      flag=1;
	      count++;
	    }
	}
    }
  for(i=0;i<n;i++)
    {
      printf("%d",A[i]);
      if(i!=n-1)
	printf(" ");
    }
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

