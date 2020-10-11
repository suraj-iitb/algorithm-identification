#include <stdio.h>

int main ()
{
  int i,j,num,tmp,count=0,A[100];

  scanf("%d",&num);

  for(i=0;i<num;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<num;i++)
    {
      for(j=num-1;j>=i+1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      tmp=A[j];
	      A[j]=A[j-1];
	      A[j-1]=tmp;
	      count++;
	    }
	}
    }

  for(i=0;i<num-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d",A[num-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}    
