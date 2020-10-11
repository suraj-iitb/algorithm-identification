#include <stdio.h>

int main()
{
  int n,i,j,flag,m=0,koukan;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  for(i=0;i<n;i++)
    {
      for(j=n-1;j>i;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      koukan=A[j-1];
	      A[j-1]=A[j];
	      A[j]=koukan;
	      m++;
	    }
	}
    }

  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n%d\n",A[n-1],m);
  return 0;
}
