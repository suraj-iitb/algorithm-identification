#include <stdio.h>

int main()
{
  int a,A[100],i,j,flag=1,chan=0,count=0;
  scanf("%d",&a);
  for(i=0;i<a;i++)scanf("%d",&A[i]);
  for(i=0;i<a;i++)
    {
      for(j=a-1;j>=1;j--)
	{
	  if( A[j] < A[j-1])
	    {
	      chan=A[j];
	      A[j]=A[j-1];
	      A[j-1]=chan;
	      count++;
	    }
	}
    }
  for(i=0;i<a;i++){
    printf("%d",A[i]);
    if(i!=a-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

