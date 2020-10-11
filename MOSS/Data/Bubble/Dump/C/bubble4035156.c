#include <stdio.h>
int main()
{
  int x,i,j,key,A[100],k,count = 0,flag = 1;
  scanf("%d",&x);
  
  for(i = 0; i < x; i++)
    scanf("%d",&A[i]);

  while(flag == 1)
    {
      flag = 0;
      for(j = x-1; j>0; j--)
	{	    
	  if(A[j] < A[j-1])
	    {
	      key = A[j];
	      A[j] = A[j-1];
	      A[j-1] = key;
	      flag = 1;
	      count++;
	    }	  	  
	}
    }

  for(k = 0; k < x; k++)
    {
      printf("%d",A[k]);
      if(k < x-1)
	printf(" ");
    }
  printf("\n%d\n",count);
  return 0;  
}
