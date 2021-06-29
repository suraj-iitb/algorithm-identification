#include <stdio.h>
int main ()
{
  int i,j,num,tmp,count=0,min,A[100];

  scanf("%d",&num);

  for(i=0;i<num;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=0;i<num;i++)
    {
      min=i;
      for(j=i;j<num;j++)
	{
	  if(A[j]<A[min])
	    {
	      min=j;
	    }
	}
      tmp=A[i];
      A[i]=A[min];
      A[min]=tmp;
      if(i!=min) count++;
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
